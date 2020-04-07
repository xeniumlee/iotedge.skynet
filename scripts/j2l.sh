#!/bin/sh

ROOT=$(dirname $0)/..
LUA=${ROOT}/skynet/3rd/lua/lua

STAT="package.cpath = \"${ROOT}/bin/?.so;${ROOT}/bin/prebuilt/?.so\" \
      package.path = \"${ROOT}/lualib/?.lua\" \
      local cjson = require 'cjson' \
      local dump = require 'utils.dump' \
      local f = io.open('$1') \
      if f then \
          local data = f:read('a') \
          data = cjson.decode(data) \
          print(dump(data)) \
      end"

if [ -n "$2" ]; then
    ${LUA} -e "${STAT}" > $2
else
    ${LUA} -e "${STAT}"
fi
