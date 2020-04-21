#!/bin/sh

DIRS="app lualib service examples"

echo "---- print ----"
for DIR in $DIRS; do
    grep -r "print(" $DIR
done

echo "---- debug ----"
for DIR in $DIRS; do
    grep -r --exclude="log.lua" "log.debug(" $DIR
done

echo "---- luac ----"
find $DIRS -name "*.luac" |xargs rm -f

echo "---- tab ----"
find $DIRS -name "*.lua" |xargs -I {} sh -c "expand -t 4 {} | sponge {}"

echo "---- loc ----"
find $DIRS -name "*.lua" |xargs wc -l |grep total

echo "---- luacheck ----"
ROOT=$(dirname $0)/..
LUA=${ROOT}/skynet/3rd/lua/lua

export LUA_CPATH="${ROOT}/bin/?.so;${ROOT}/bin/prebuilt/?.so"
export LUA_PATH="${ROOT}/3rd/?.lua;${ROOT}/3rd/?/init.lua"

${LUA} ${ROOT}/3rd/luacheck/main.lua --config ${ROOT}/dev/luacheckrc $DIRS
