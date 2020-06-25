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
- [x] VPN by WireGuard
- [x] Websocket proxy (e.g. for noVNC)
- [x] Modbus TCP/RTU(ASCII)/RTU(ASCII) over TCP
- [x] Simens S7
- [x] Kafka publisher
- [x] MQTT publisher
- [x] File publisher
- [x] OPCUA: Binding [open62541](https://open62541.org/)
- [x] Python runtime
- [ ] HTTP data acquisition
- [ ] BACnet: Binding [bacnet-stack](http://bacnet.sourceforge.net/)
## Build & Run
### Build
* git clone https://github.com/cloudwu/skynet.git
* mkdir -p bin/prebuilt
* build dependencies
* make
#### Build python
```
apt-get install libbz2-dev liblzma-dev zlib1g-dev libffi-dev
https://www.python.org/ftp/python/3.8.3/Python-3.8.3.tgz
./configure --enable-shared
make
cp libpython3.8.a ../iotedge/bin/prebuilt/libpython.a.3.8
```
#### Build openssl
```
https://github.com/openssl/openssl/archive/OpenSSL_1_1_1g.tar.gz
./config no-tests
make
cp libcrypto.a ../iotedge/bin/prebuilt/libcrypto.a.1.1.1g
cp libssl.a ../iotedge/bin/prebuilt/libssl.a.1.1.1g
```
#### Build snap7
```
cd 3rd/snap7-1.4.2/build/unix
make -f x86_64_linux.mk clean|all|install
make -f arm_v7_linux.mk clean|all|install
cp ../bin/x86_64/libsnap7.a ../../../../bin/prebuilt/libsnap7.a.1.4.2
```
#### Build open62541
```
https://github.com/open62541/open62541/archive/v1.1.tar.gz
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DUA_ENABLE_ENCRYPTION_OPENSSL=ON -DOPENSSL_CRYPTO_LIBRARY="../../iotedge/bin/prebuilt/libcrypto.a.1.1.1g" -DOPENSSL_SSL_LIBRARY="../../iotedge/bin/prebuilt/libssl.a.1.1.1g" -DOPENSSL_INCLUDE_DIR="../../iotedge/3rd/openssl-1.1.1g" ..
make
cp bin/libopen62541.a ../../iotedge/bin/prebuilt/libopen62541.a.1.1
```
### Run
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
* git.zx2c4.com/wireguard-go
