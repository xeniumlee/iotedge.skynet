local skynet = require "skynet"
local api = require "api"
local lfs = require "lfs"
local sys = require "sys"
local log = require "log"
local sqlite3 = require('lsqlite3complete')
local text = require("text").store

local applist = {}
local devlist = {}

local db_root = sys.db_root

local open_f = sqlite3.OPEN_READWRITE +
               sqlite3.OPEN_URI +
               sqlite3.OPEN_NOMUTEX


local tbl = "data"

local dev_col = "dev"
local dev_idx = 1
local ttl_col = "ttl"
local ttl_idx = 2
local data_col = "data"
local data_idx = 3

local idx = "ttl_idx"
local count = 5

local sql = {
    insert = string.format("INSERT INTO %s VALUES (?%d, (SELECT julianday('now') + ?%d), ?%d);",
        tbl, dev_idx, ttl_idx, data_idx),
    latest = string.format("SELECT rowid, %s, %s FROM %s INDEXED BY %s ORDER BY %s DESC LIMIT %d;",
        dev_col, data_col, tbl, idx, ttl_col, count),
    delete = string.format("DELETE FROM %s WHERE rowid = ?;", tbl),
}

local sql_retire = string.format("DELETE FROM %s WHERE %s < (SELECT julianday('now'));", tbl, ttl_col)
local sql_vacuum = "VACUUM;"
local sql_create = string.format([[
        BEGIN;
        CREATE TABLE IF NOT EXISTS %s (
            %s TEXT NOT NULL,
            %s REAL NOT NULL,
            %s BLOB NOT NULL
        );
        CREATE INDEX IF NOT EXISTS %s ON %s (%s);
        COMMIT;
        ]], tbl, dev_col, ttl_col, data_col, idx, tbl, ttl_col)

local function db_file(app)
    return string.format("%s/%s/%s",
        lfs.currentdir(),
        db_root,
        app.name)
end

local function db_name(app)
    return "file:"..db_file(app)
end

local function retire(app)
    log.error(text.retire, app.name)
    app.db:exec(sql_retire)
end

local function vacuum(app)
    log.error(text.vacuum, app.name)
    app.db:exec(sql_vacuum)
end

local function post_interval()
    return math.random(500, 1000)
end

local function retry_interval()
    return math.random(100, 200)
end

local function close(app)
    local db = app.db
    if db and db:isopen() then
        log.error(text.closed , app.name)
        db:close_vm()
        db:close()
    end
    app.db = false
end

local function open(app)
    local n = db_name(app)
    local retry = 0
    local max_retry = 3
    while not app.db do
        local db = sqlite3.open(n, open_f+sqlite3.OPEN_CREATE)
        if db and db:exec(sql_create) == sqlite3.OK then
            log.error(text.open_suc, app.name)
            for k, v in pairs(sql) do
                app[k] = db:prepare(v)
            end
            app.db = db
            return
        else
            if db then
                db:close()
            end
            if retry < max_retry then
                retry = retry + 1
                skynet.sleep(retry_interval())
            else
                log.error(text.open_fail, app.name)
                os.remove(db_file(app))
                return
            end
        end
    end
end

local function try_open(app)
    local f = db_file(app)
    local attr = lfs.attributes(f)
    if attr and attr.mode == "file" then
        local n = db_name(app)
        local retry = 0
        local max_retry = 3
        while not app.db do
            local db = sqlite3.open(n, open_f)
            if db then
                log.error(text.open_suc, app.name)
                for k, v in pairs(sql) do
                    app[k] = db:prepare(v)
                end
                app.db = db
                return
            else
                if retry < max_retry then
                    retry = retry + 1
                    skynet.sleep(retry_interval())
                else
                    log.error(text.open_fail, app.name)
                    os.remove(f)
                    return
                end
            end
        end
    end
end

local function post(app, addr)
    retire(app)
    while app.db and app.online do
        local done = true
        local stmt = app.latest
        local stmt_delete = app.delete
        stmt:reset()
        for id, dev, data in stmt:urows() do
            done = false
            skynet.send(addr, "lua", "payload", dev, data)
            stmt_delete:reset()
            stmt_delete:bind_values(id)
            stmt_delete:step()
        end
        if done then
            log.error(text.post_done, app.name)
            vacuum(app)
            close(app)
            break
        else
            skynet.sleep(post_interval())
        end
    end
end

local function init_store(app, dev, ttl)
    return function(data)
        while app.db do
            local stmt = app.insert
            stmt:reset()
            stmt:bind(dev_idx, dev)
            stmt:bind(ttl_idx, ttl)
            stmt:bind_blob(data_idx, data)
            if stmt:step() == sqlite3.DONE then
                break
            else
                skynet.sleep(retry_interval())
            end
        end
    end
end

local command = {}
function command.stop(addr)
    for _, app in pairs(applist) do
        close(app)
    end
end

function command.enable(addr, name)
    log.error(text.enable, name)
    if not applist[addr] then
        applist[addr] = {}
    end
    local app = applist[addr]
    app.name = name
    app.online = false
    app.store = {}
    close(app)
end

function command.online(addr)
    local app = applist[addr]
    if app then
        log.error(text.online, app.name)
        app.online = true
        try_open(app)
        if app.db then
            post(app, addr)
        end
    end
end

function command.offline(addr)
    local app = applist[addr]
    if app then
        log.error(text.offline, app.name)
        app.online = false
    end
end

function command.payload(addr, dev, data)
    local app = applist[addr]
    local ttl = devlist[dev]
    if app and ttl then
        if not app.store[dev] then
            app.store[dev] = init_store(app, dev, ttl)
        end
        open(app)
        if app.db then
            app.store[dev](data)
        end
    end
end

function command.dev_online(addr, dev, ttl)
    if devlist[dev] ~= ttl then
        devlist[dev] = ttl
        for _, app in pairs(applist) do
            app.store[dev] = false
        end
    end
end

skynet.start(function()
    math.randomseed(skynet.time())
    pcall(lfs.mkdir, db_root)
    skynet.dispatch("lua", function(session, addr, cmd, ...)
        local f = command[cmd]
        if f then
            f(addr, ...)
        end
    end)
end)
