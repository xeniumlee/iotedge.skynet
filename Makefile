SKYNET_PATH = skynet
LUA_SRC = $(SKYNET_PATH)/3rd/lua
SKYNET_SRC = $(SKYNET_PATH)/skynet-src

BUILD_PATH = bin
PREBUILT_PATH = bin/prebuilt
LUA_LIB_SRC = lualib-src

OS = linux
CC = gcc
GCCVERSION = $(shell gcc -dumpversion |cut -f1 -d.)
ifeq ($(GCCVERSION), 8)
	CXXSTD = c++17
	CXXFLAGS = CXX17
else
	CXXSTD = c++14
	CXXFLAGS = CXX14
endif

.PHONY: skynet

all:

skynet:
	cd $(SKYNET_PATH) && $(MAKE) all \
		PLAT=$(OS) \
		CC=$(CC) \
		SKYNET_LIBS="-lpthread -lm -ldl -lrt" \
		SHARED="-fPIC -shared" \
		EXPORT="-Wl,-E" \
		SKYNET_BUILD_PATH="../$(BUILD_PATH)" \
		LUA_CLIB_PATH="../$(BUILD_PATH)" \
		CSERVICE_PATH="../$(BUILD_PATH)"

skynetclean:
	cd $(SKYNET_PATH) && $(MAKE) clean \
		SKYNET_BUILD_PATH="../$(BUILD_PATH)" \
		BUILD_PATH="../$(BUILD_PATH)" \
		CSERVICE_PATH="../$(BUILD_PATH)"

LUA_ZLIB_BIN = $(BUILD_PATH)/zlib.so
LUA_ZLIB_SRC = $(LUA_LIB_SRC)/lua-zlib.c
LUA_ZLIB_CC = $(CC) -O2 -Wall -fPIC -shared
$(LUA_ZLIB_BIN): $(LUA_ZLIB_SRC)
	$(LUA_ZLIB_CC) $^ -o $@ -I$(LUA_SRC) -lm -lz

SSL_BIN = $(PREBUILT_PATH)/libssl.a.1.1.1g $(PREBUILT_PATH)/libcrypto.a.1.1.1g
SSL_SRC = 3rd/openssl-1.1.1g
LUA_TLS_BIN = $(BUILD_PATH)/ltls.so
LUA_TLS_SRC = $(LUA_LIB_SRC)/ltls.c
LUA_TLS_CC = $(CC) -O2 -Wall -fPIC -shared
$(LUA_TLS_BIN): $(LUA_TLS_SRC) $(SSL_BIN)
	$(LUA_TLS_CC) $^ -o $@ -I$(LUA_SRC) -I$(SSL_SRC) -pthread

SNAP7_BIN = $(PREBUILT_PATH)/libsnap7.a.1.4.2
SNAP7_SRC = 3rd/snap7-1.4.2/release
LUA_SNAP7_BIN = $(BUILD_PATH)/snap7.so
LUA_SNAP7_SRC = $(LUA_LIB_SRC)/lua-snap7.cpp
LUA_SNAP7_CXX = $(CXX) -std=$(CXXSTD) -O2 -Wall -pedantic -fPIC -shared -D$(CXXFLAGS)
$(LUA_SNAP7_BIN): $(LUA_SNAP7_SRC) $(SNAP7_SRC)/snap7.cpp $(SNAP7_BIN)
	$(LUA_SNAP7_CXX) $^ -o $@ -I$(LUA_SRC) -I$(SNAP7_SRC) -I$(SKYNET_SRC) -pthread -lrt

SSL_BIN = $(PREBUILT_PATH)/libssl.a.1.1.1g $(PREBUILT_PATH)/libcrypto.a.1.1.1g
OPEN62541_BIN = $(PREBUILT_PATH)/libopen62541.a.1.1
OPEN62541_SRC = 3rd/open62541-1.1
OPEN62541_SRC_GENERATED = ../open62541-1.1/build/src_generated
LUA_OPCUA_BIN = $(BUILD_PATH)/opcua.so
LUA_OPCUA_SRC = $(LUA_LIB_SRC)/lua-opcua.cpp
LUA_OPCUA_CXX = $(CXX) -std=$(CXXSTD) -O2 -Wall -pedantic -fPIC -shared -D$(CXXFLAGS)
$(LUA_OPCUA_BIN): $(LUA_OPCUA_SRC) $(OPEN62541_BIN) $(SSL_BIN)
	$(LUA_OPCUA_CXX) $^ -o $@ -I$(LUA_SRC) -I$(OPEN62541_SRC) -I$(OPEN62541_SRC_GENERATED) -pthread

LUA_SERIAL_BIN = $(BUILD_PATH)/serial.so
LUA_SERIAL_SRC = $(LUA_LIB_SRC)/lua-serial.cpp
LUA_SERIAL_CXX = $(CXX) -std=$(CXXSTD) -O2 -Wall -pedantic -fPIC -shared -D$(CXXFLAGS)
$(LUA_SERIAL_BIN): $(LUA_SERIAL_SRC)
	$(LUA_SERIAL_CXX) $^ -o $@ -I$(LUA_SRC)

# ./python-config --cflags
# ./python-config --ldflags
PYTHON_BIN = $(PREBUILT_PATH)/libpython.a.3.8
PYTHON_SRC = 3rd/python-3.8
LUA_PYTHON_BIN = $(BUILD_PATH)/python.so
LUA_PYTHON_SRC = $(LUA_LIB_SRC)/lua-python.cpp
LUA_PYTHON_CXX = $(CXX) -std=$(CXXSTD) -O2 -Wall -pedantic -fPIC -shared -D$(CXXFLAGS) -DNDEBUG
$(LUA_PYTHON_BIN): $(LUA_PYTHON_SRC) $(PYTHON_BIN)
	$(LUA_PYTHON_CXX) $^ -o $@ -I$(LUA_SRC) -I$(PYTHON_SRC) -pthread -lcrypt -ldl -lutil -lm

all: skynet $(LUA_PYTHON_BIN) $(LUA_TLS_BIN) $(LUA_SNAP7_BIN) $(LUA_SERIAL_BIN) $(LUA_OPCUA_BIN) $(LUA_ZLIB_BIN)

clean:
	rm -f $(LUA_PYTHON_BIN) $(LUA_TLS_BIN) $(LUA_SNAP7_BIN) $(LUA_SERIAL_BIN) $(LUA_OPCUA_BIN) $(LUA_ZLIB_BIN)

cleanall: skynetclean clean
