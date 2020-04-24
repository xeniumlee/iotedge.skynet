## Design
* Control processor: console, MQTT, etc.
* Data processor: To fetch, process, and publish data
* Pipeline: To link data processors together
## Feature
- [x] MQTT controller (Plain/TLS/Websocket)
- [x] Console controller (Authentication)
- [x] Websocket controller (Authentication)
- [x] System/Appliation Upgrade (Remote SW repository)
- [x] Configuration storage
- [x] Data storage (Data retention)
- [x] Json/MessagePack pack 
- [x] Zlib compressor
- [x] COV(change of value) publish
- [x] Buffer/Group publish 
- [x] Log rotate
- [x] Proxy support by FRP
- [x] Monitor by NodeExporter
- [x] VPN by OpenVPN
- [x] Modbus TCP/RTU(ASCII)/RTU(ASCII) over TCP
- [x] Simens S7
- [x] Kafka publisher
- [x] MQTT publisher
- [x] File publisher
- [ ] HTTP data acquisition
- [ ] OPCUA: Binding [open62541](https://open62541.org/)
- [ ] BACnet: Binding [bacnet-stack](http://bacnet.sourceforge.net/)
## Build & Run
### Build
* git clone https://github.com/cloudwu/skynet.git
* mkdir -p bin/prebuilt
* Build 3rd/openssl-1.1.1d into bin/prebuilt
* Build 3rd/snap7-1.4.2 into bin/prebuilt
* make all
### Run
* Put necessary dependences into bin/prebuilt
* cp config.xx config
* Edit config
* ./bin/skynet iotedge.config
* telnet localhost 30000
* Type help
### Production
* Check dev/release.sh & scripts/install.sh
## Dependences
* github.com/cloudwu/lua-cjson
* github.com/keplerproject/luafilesystem
* github.com/brimworks/lua-zlib
* github.com/fatedier/frp
* github.com/prometheus/node_exporter
* lua.sqlite.org: lsqlite3complete
