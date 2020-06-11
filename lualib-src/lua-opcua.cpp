#include "open62541/client_highlevel.h"
#include "open62541/client_config_default.h"
#include <open62541/plugin/log_stdout.h>

#define SOL_ALL_SAFETIES_ON 1

#ifdef CXX17
#include "sol3.hpp"
#else
#include "sol2.hpp"
#endif

#define RETURN_OK(R) R.push_back({ L, sol::in_place_type<bool>, true });

#define RETURN_VARIANT(R, T, V) { \
    RETURN_OK(R) \
	R.push_back({ L, sol::in_place_type<T>, *(T*)V.data }); \
}

#define RETURN_STRING(R, V) { \
    UA_String* str = (UA_String*)V.data; \
    RETURN_OK(R) \
	R.push_back({ L, sol::in_place_type<std::string>, std::string(reinterpret_cast<const char*>(str->data), str->length) }); \
}

#define RETURN_VALUE(R, T, V) { \
    RETURN_OK(R) \
	R.push_back({ L, sol::in_place_type<T>, V }); \
}

#define RETURN_ERROR(R, E) { \
    R.push_back({ L, sol::in_place_type<bool>, false }); \
	R.push_back({ L, sol::in_place_type<std::string>, E }); \
}

namespace opcua {
    std::string err_not_supported = "Not supported data type";
    std::string err_register_failed = "Register node failed";

    void stateCallback(UA_Client *client, UA_ClientState clientState) {
        switch(clientState) {
            case UA_CLIENTSTATE_DISCONNECTED:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "The client is disconnected");
                break;
            case UA_CLIENTSTATE_WAITING_FOR_ACK:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Waiting for ack");
                break;
            case UA_CLIENTSTATE_CONNECTED:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                            "A TCP connection to the server is open");
                break;
            case UA_CLIENTSTATE_SECURECHANNEL:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                            "A SecureChannel to the server is open");
                break;
            case UA_CLIENTSTATE_SESSION:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "A session with the server is open");
                break;
            case UA_CLIENTSTATE_SESSION_RENEWED:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                            "A session with the server is open (renewed)");
                break;
            case UA_CLIENTSTATE_SESSION_DISCONNECTED:
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Session disconnected");
                break;
        }
        return;
    }

    class Client {
    private:
        UA_Client* _client;
        UA_Int16 _ns = -1;
        std::unordered_map<UA_UInt32, UA_UInt16> _data_type;

    private:
        auto setNamespaceIndex(const std::string& Namespace) {
            UA_UInt16 idx;
            UA_String ns = UA_STRING(const_cast<char*>(Namespace.data()));
            UA_StatusCode code = UA_Client_NamespaceGetIndex(_client, &ns, &idx);
            if (code == UA_STATUSCODE_GOOD) {
                _ns = idx;
            }
            return code;
        }

        auto setDataType(UA_UInt32 NodeId, UA_UInt16 Type) {
            _data_type[NodeId] = Type;
        }

        auto getDataType(UA_UInt32 NodeId) {
            auto t = _data_type.find(NodeId);
            if (t != _data_type.end()) {
                return t->second;
            } else {
                UA_Variant v;
                UA_Variant_init(&v);
                const UA_NodeId nodeId = UA_NODEID_NUMERIC(_ns, NodeId);
                UA_StatusCode code = UA_Client_readValueAttribute(_client, nodeId, &v);

                if (code == UA_STATUSCODE_GOOD && UA_Variant_isScalar(&v)) {
                    setDataType(NodeId, v.type->typeIndex);
                    return _data_type[NodeId];
                } else {
                    return (UA_UInt16)UA_TYPES_COUNT;
                }
            }
        }

        auto doWrite(UA_UInt32 NodeId, void* val, sol::this_state L) {
            sol::variadic_results ret;
            UA_Variant v;
            UA_UInt16 t = getDataType(NodeId);
            if (t != UA_TYPES_COUNT) {
                UA_Variant_setScalar(&v, val, &UA_TYPES[t]);
                const UA_NodeId nodeId = UA_NODEID_NUMERIC(_ns, NodeId);
                UA_StatusCode code = UA_Client_writeValueAttribute(_client, nodeId, &v);
                if (code == UA_STATUSCODE_GOOD) {
                    RETURN_OK(ret)
                } else {
                    RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
                }
            } else {
                RETURN_ERROR(ret, err_not_supported)
            }
            UA_Variant_clear(&v);
            return ret;
        }

    public:
        Client() {
            _client = UA_Client_new();
            UA_ClientConfig *config = UA_Client_getConfig(_client);
            UA_ClientConfig_setDefault(config);
            config->stateCallback = stateCallback;
        }

        ~Client() {
            UA_Client_disconnect(_client);
            UA_Client_delete(_client);
        }

        auto Connect(const std::string& EndpointUrl, const std::string& Namespace,
                sol::this_state L) {
            sol::variadic_results ret;
            UA_StatusCode code = UA_Client_connect(_client, EndpointUrl.data());
            if (code == UA_STATUSCODE_GOOD) {
                code = setNamespaceIndex(Namespace);
                if (code == UA_STATUSCODE_GOOD) {
                    RETURN_OK(ret)
                } else {
                    UA_Client_disconnect(_client);
                    RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
                }
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }
            return ret;
        }

        auto ConnectUsername(const std::string& EndpointUrl, const std::string& Namespace,
                const std::string& Username, const std::string& Password,
                sol::this_state L) {
            sol::variadic_results ret;
            UA_StatusCode code =  UA_Client_connect_username(_client, EndpointUrl.data(), Username.data(), Password.data());
            if (code == UA_STATUSCODE_GOOD) {
                code = setNamespaceIndex(Namespace);
                if (code == UA_STATUSCODE_GOOD) {
                    RETURN_OK(ret)
                } else {
                    UA_Client_disconnect(_client);
                    RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
                }
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }
            return ret;
        }

        auto Disconnect(sol::this_state L) {
            sol::variadic_results ret;
            UA_StatusCode code = UA_Client_disconnect(_client);
            if (code == UA_STATUSCODE_GOOD) {
                RETURN_OK(ret)
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }
            return ret;
        }

        auto Info(sol::this_state L) {
            sol::state_view lua(L);
            sol::table info = lua.create_table();

            info["state"] = UA_Client_getState(_client);
            UA_ClientConfig *config = UA_Client_getConfig(_client);
            info["timeout"] = config->timeout;
            info["securechannel_lifetime"] = config->secureChannelLifeTime;
            info["requestedsession_timeout"] = config->requestedSessionTimeout;
            info["connectivity_checkInterval"] = config->connectivityCheckInterval;

            return info;
        }

        auto Read(UA_UInt32 NodeId, sol::this_state L) {
            UA_Variant v;
            UA_Variant_init(&v);
            const UA_NodeId nodeId = UA_NODEID_NUMERIC(_ns, NodeId);
            UA_StatusCode code = UA_Client_readValueAttribute(_client, nodeId, &v);

            sol::variadic_results ret;
            if (code == UA_STATUSCODE_GOOD) {
                if (UA_Variant_isScalar(&v)) {
                    setDataType(NodeId, v.type->typeIndex);

                    switch(v.type->typeIndex) {
                        case UA_TYPES_BOOLEAN:
                            RETURN_VARIANT(ret, UA_Boolean, v)
                            break;
                        case UA_TYPES_SBYTE:
                            RETURN_VARIANT(ret, UA_SByte, v)
                            break;
                        case UA_TYPES_BYTE:
                            RETURN_VARIANT(ret, UA_Byte, v)
                            break;
                        case UA_TYPES_INT16:
                            RETURN_VARIANT(ret, UA_Int16, v)
                            break;
                        case UA_TYPES_UINT16:
                            RETURN_VARIANT(ret, UA_UInt16, v)
                            break;
                        case UA_TYPES_INT32:
                            RETURN_VARIANT(ret, UA_Int32, v)
                            break;
                        case UA_TYPES_UINT32:
                            RETURN_VARIANT(ret, UA_UInt32, v)
                            break;
                        case UA_TYPES_INT64:
                            RETURN_VARIANT(ret, UA_Int64, v)
                            break;
                        case UA_TYPES_UINT64:
                            RETURN_VARIANT(ret, UA_UInt64, v)
                            break;
                        case UA_TYPES_FLOAT:
                            RETURN_VARIANT(ret, UA_Float, v)
                            break;
                        case UA_TYPES_DOUBLE:
                            RETURN_VARIANT(ret, UA_Double, v)
                            break;
                        case UA_TYPES_STRING:
                            RETURN_STRING(ret, v)
                            break;
                        default:
                            RETURN_ERROR(ret, err_not_supported)
                    }
                } else {
                    RETURN_ERROR(ret, err_not_supported)
                }
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }

            UA_Variant_clear(&v);
            return ret;
        }

        auto WriteBoolean(UA_UInt32 NodeId, UA_Boolean val, sol::this_state L) {
            return doWrite(NodeId, static_cast<void*>(&val), L);
        }

        auto WriteInteger(UA_UInt32 NodeId, UA_Int64 val, sol::this_state L) {
            return doWrite(NodeId, static_cast<void*>(&val), L);
        }

        auto WriteDouble(UA_UInt32 NodeId, UA_Double val, sol::this_state L) {
            return doWrite(NodeId, static_cast<void*>(&val), L);
        }

        auto WriteString(UA_UInt32 NodeId, const std::string& val, sol::this_state L) {
            UA_String str = UA_STRING(const_cast<char*>(val.data()));
            return doWrite(NodeId, static_cast<void*>(&str), L);
        }

        auto Register(const std::string& NodeId, sol::this_state L) {
            UA_RegisterNodesRequest req;
            UA_RegisterNodesRequest_init(&req);

            req.nodesToRegister = UA_NodeId_new();
            req.nodesToRegister[0] = UA_NODEID_STRING(_ns, const_cast<char*>(NodeId.data()));
            req.nodesToRegisterSize = 1;

            UA_RegisterNodesResponse res = UA_Client_Service_registerNodes(_client, req);
            UA_StatusCode code = res.responseHeader.serviceResult;

            sol::variadic_results ret;
            if (code == UA_STATUSCODE_GOOD) {
                if (res.registeredNodeIdsSize == 1) {
                    UA_UInt32 id = res.registeredNodeIds[0].identifier.numeric;
                    RETURN_VALUE(ret, UA_UInt32, id)
                } else {
                    RETURN_ERROR(ret, err_register_failed)
                }
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }

            UA_RegisterNodesRequest_clear(&req);
            UA_RegisterNodesResponse_clear(&res);
            return ret;
        }

        auto UnRegister(UA_UInt32 NodeId, sol::this_state L) {
            UA_UnregisterNodesRequest req;
            UA_UnregisterNodesRequest_init(&req);

            req.nodesToUnregister = UA_NodeId_new();
            req.nodesToUnregister[0] = UA_NODEID_NUMERIC(_ns, NodeId);
            req.nodesToUnregisterSize = 1;

            UA_UnregisterNodesResponse res = UA_Client_Service_unregisterNodes(_client, req);
            UA_StatusCode code = res.responseHeader.serviceResult;

            sol::variadic_results ret;
            if (code == UA_STATUSCODE_GOOD) {
                RETURN_OK(ret)
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }

            UA_UnregisterNodesRequest_clear(&req);
            UA_UnregisterNodesResponse_clear(&res);
            return ret;
        }
    };

    sol::table open(sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        module.new_usertype<Client>("client",
            "connect", sol::overload(&Client::Connect,
                                     &Client::ConnectUsername),
            "disconnect", &Client::Disconnect,
            "read", &Client::Read,
            "write", sol::overload(&Client::WriteBoolean,
                                   &Client::WriteInteger,
                                   &Client::WriteDouble,
                                   &Client::WriteString),
            "register", &Client::Register,
            "unregister", &Client::UnRegister,
            "info", &Client::Info
        );
        return module;
    }
}

extern "C" int luaopen_snap7(lua_State *L) {
    return sol::stack::call_lua(L, 1, opcua::open);
}
