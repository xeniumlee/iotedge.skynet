CXXSTD=c++17
CXXFLAGS=CXX17
#CXXSTD=c++14
#CXXFLAGS=CXX14

SKYNET_PATH = skynet
LUA_SRC = $(SKYNET_PATH)/3rd/lua

BUILD_PATH = bin
PREBUILT_PATH = bin/prebuilt
LUA_LIB_SRC = lualib-src

OS = linux
CC = gcc

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

SSL_BIN = $(PREBUILT_PATH)/libssl.a.1.1.1d $(PREBUILT_PATH)/libcrypto.a.1.1.1d
SSL_SRC = 3rd/openssl-1.1.1d
LUA_TLS_BIN = $(BUILD_PATH)/ltls.so
LUA_TLS_SRC = $(LUA_LIB_SRC)/ltls.c
LUA_TLS_CC = $(CC) -O2 -Wall -fPIC -shared
$(LUA_TLS_BIN): $(LUA_TLS_SRC) $(SSL_BIN)
	$(LUA_TLS_CC) $^ -o $@ -I$(LUA_SRC) -I$(SSL_SRC) -lpthread

SNAP7_BIN = $(PREBUILT_PATH)/libsnap7.a.1.4.2
SNAP7_SRC = 3rd/snap7-1.4.2/release
LUA_SNAP7_BIN = $(BUILD_PATH)/snap7.so
LUA_SNAP7_SRC = $(LUA_LIB_SRC)/lua-snap7.cpp
LUA_SNAP7_CXX = $(CXX) -std=$(CXXSTD) -O2 -Wall -pedantic -fPIC -shared -D$(CXXFLAGS)
$(LUA_SNAP7_BIN): $(LUA_SNAP7_SRC) $(SNAP7_SRC)/snap7.cpp $(SNAP7_BIN)
	$(LUA_SNAP7_CXX) $^ -o $@ -I$(LUA_SRC) -I$(SNAP7_SRC) -lpthread -lrt

LUA_SERIAL_BIN = $(BUILD_PATH)/serial.so
LUA_SERIAL_SRC = $(LUA_LIB_SRC)/lua-serial.cpp
LUA_SERIAL_CXX = $(CXX) -std=$(CXXSTD) -O2 -Wall -pedantic -fPIC -shared -D$(CXXFLAGS)
$(LUA_SERIAL_BIN): $(LUA_SERIAL_SRC)
	$(LUA_SERIAL_CXX) $^ -o $@ -I$(LUA_SRC)

all: skynet $(LUA_TLS_BIN) $(LUA_SNAP7_BIN) $(LUA_SERIAL_BIN)

clean:
	rm -f $(LUA_SNAP7_BIN) $(LUA_TLS_BIN) $(LUA_SERIAL_BIN)

cleanall: skynetclean clean
