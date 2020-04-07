## Design
* Control processor: console, MQTT, etc.
* Data processor: To fetch, process, and publish data
* Pipeline: To link data processors together
## Build & Run
### Build
* git clone https://github.com/cloudwu/skynet.git
* mkdir -p bin/prebuilt
* Build 3rd/openssl-1.1.1d into bin/prebuilt
* Build 3rd/snap7-1.4.2 into bin/prebuilt
* make all
### Run
* Put necessary dependences into bin/prebuilt
* cp config.xx.lua config.lua
* Edit config.lua
* ./bin/skynet skynet.config
* telnet localhost 30000
* Type help
### Production
* Check scripts/release.sh & scripts/install.sh
## Dependences
* github.com/cloudwu/lua-cjson
* github.com/keplerproject/luafilesystem
* github.com/brimworks/lua-zlib
* github.com/fatedier/frp
* github.com/prometheus/node_exporter
* lua.sqlite.org: lsqlite3complete
## TODO
* OPCUA: Binding [open62541](https://open62541.org/)
* BACnet: Binding [bacnet-stack](http://bacnet.sourceforge.net/)
