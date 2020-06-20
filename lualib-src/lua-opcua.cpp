#include "open62541/client_highlevel.h"
#include "open62541/client_config_default.h"

#include "open62541/plugin/log_stdout.h"

#define SOL_ALL_SAFETIES_ON 1

#ifdef CXX17
#include "sol3.hpp"
#else
#include "sol2.hpp"
#endif

namespace opcua {

#define RETURN_OK(R) R.push_back({ L, sol::in_place_type<bool>, true });

#define RETURN_VALUE(R, T, V) { \
	R.push_back({ L, sol::in_place_type<T>, V }); \
}

#define RETURN_ERROR(R, E) { \
    R.push_back({ L, sol::in_place_type<bool>, false }); \
	R.push_back({ L, sol::in_place_type<std::string>, E }); \
}

    const size_t maxRead = 200;
    const std::string errNotSupportedDataType = "Not supported data type";

    class Client {
    private:
        UA_Client* _client;
        UA_Int16 _ns = -1;

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

        auto getNodeType(const UA_NodeId& NodeId) {
            UA_Variant v;
            UA_Variant_init(&v);
            UA_StatusCode code = UA_Client_readValueAttribute(_client, NodeId, &v);

            UA_Int16 ret;
            if (code == UA_STATUSCODE_GOOD && UA_Variant_isScalar(&v)) {
                ret = v.type->typeIndex;
            } else {
                ret = -1;
            }
            UA_Variant_clear(&v);
            return ret;
        }

        auto doWrite(UA_UInt32 NodeId, UA_Int16 DataTypeIndex, void* Val, sol::this_state L) {
            sol::variadic_results ret;
            UA_Variant v;

            if (DataTypeIndex > -1 && DataTypeIndex < UA_TYPES_COUNT) {
                const UA_NodeId& id = UA_NODEID_NUMERIC(_ns, NodeId);
                UA_Variant_setScalar(&v, Val, &UA_TYPES[DataTypeIndex]);

                UA_StatusCode code = UA_Client_writeValueAttribute(_client, id, &v);
                if (code == UA_STATUSCODE_GOOD) {
                    RETURN_OK(ret)
                } else {
                    RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
                }
            } else {
                RETURN_ERROR(ret, errNotSupportedDataType)
            }
            return ret;
        }

    public:
        Client(const std::string& ApplicationUri,
                const UA_MessageSecurityMode Mode,
                const std::string& Policy,
                const std::string& Cert,
                const std::string& Key) {
            _client = UA_Client_new();

            UA_ClientConfig *config = UA_Client_getConfig(_client);

            UA_ByteString *trustList = NULL;
            size_t trustListSize = 0;
            UA_ByteString *revocationList = NULL;
            size_t revocationListSize = 0;

            UA_ByteString certificate;
            certificate.length = Cert.length();
            certificate.data = (UA_Byte*)Cert.data();

            UA_ByteString privateKey;
            privateKey.length = Key.length();
            privateKey.data = (UA_Byte*)Key.data();

            UA_ClientConfig_setDefaultEncryption(
                    config, certificate, privateKey, trustList, trustListSize, revocationList, revocationListSize);

            config->clientDescription.applicationUri = UA_STRING_ALLOC(ApplicationUri.data());
            config->securityMode = Mode;
            config->securityPolicyUri = UA_STRING_ALLOC(Policy.data());

            //config->logger.log = NULL;
            //config->logger.clear = NULL;
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

            UA_StatusCode code =  UA_Client_connectUsername(_client, EndpointUrl.data(), Username.data(), Password.data());
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

        auto Configuration(sol::this_state L) {
            sol::state_view lua(L);
            sol::table c = lua.create_table();

            UA_ClientConfig *config = UA_Client_getConfig(_client);
            c["timeout"] = config->timeout;
            c["securechannel_lifetime"] = config->secureChannelLifeTime;
            c["requestedsession_timeout"] = config->requestedSessionTimeout;
            c["connectivity_checkInterval"] = config->connectivityCheckInterval;

            return c;
        }

        auto State() {
            UA_SecureChannelState s1;
            UA_SessionState s2;
            UA_StatusCode s3;
            UA_Client_getState(_client, &s1, &s2, &s3);
            return std::make_tuple(s1, s2, std::string(UA_StatusCode_name(s3)));
        }

        auto Read(sol::table NodeList, sol::this_state L) {
            size_t count = NodeList.size();

            UA_ReadValueId ids[maxRead];
            for(size_t i = 0, j = 1; i != count; i++, j++) {
                UA_ReadValueId_init(&ids[i]);

                ids[i].attributeId = UA_ATTRIBUTEID_VALUE;
                UA_UInt32 id = NodeList[j]["id"];
                ids[i].nodeId = UA_NODEID_NUMERIC(_ns, id);
            }

            UA_ReadRequest req;
            UA_ReadRequest_init(&req);
            req.nodesToRead = ids;
            req.nodesToReadSize = count;

            UA_ReadResponse res = UA_Client_Service_read(_client, req);
            UA_StatusCode code = res.responseHeader.serviceResult;
            if (code == UA_STATUSCODE_GOOD && res.resultsSize != count )
                code = UA_STATUSCODE_BADUNEXPECTEDERROR;

            sol::variadic_results ret;
            if (code != UA_STATUSCODE_GOOD) {
                UA_ReadResponse_clear(&res);
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
                return ret;
            }

            for(size_t i = 0, j = 1; i != count; i++, j++) {
                const UA_DataValue& dv = res.results[i];
                code = dv.status;

                if (code != UA_STATUSCODE_GOOD || !dv.hasValue) {
                    if (code == UA_STATUSCODE_GOOD)
                        code = UA_STATUSCODE_BADUNEXPECTEDERROR;
                    NodeList[j]["ok"] = false;
                    NodeList[j]["val"] = std::string(UA_StatusCode_name(code));
                } else {
                    const UA_Variant& v = dv.value;
                    if (UA_Variant_isScalar(&v)) {
                        switch(v.type->typeIndex) {
                            case UA_TYPES_BOOLEAN:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Boolean*>(v.data);
                                break;
                            case UA_TYPES_SBYTE:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_SByte*>(v.data);
                                break;
                            case UA_TYPES_BYTE:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Byte*>(v.data);
                                break;
                            case UA_TYPES_INT16:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Int16*>(v.data);
                                break;
                            case UA_TYPES_UINT16:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_UInt16*>(v.data);
                                break;
                            case UA_TYPES_INT32:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Int32*>(v.data);
                                break;
                            case UA_TYPES_UINT32:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_UInt32*>(v.data);
                                break;
                            case UA_TYPES_INT64:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Int64*>(v.data);
                                break;
                            case UA_TYPES_UINT64:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_UInt64*>(v.data);
                                break;
                            case UA_TYPES_FLOAT:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Float*>(v.data);
                                break;
                            case UA_TYPES_DOUBLE:
                                NodeList[j]["ok"] = true;
                                NodeList[j]["val"] = *static_cast<UA_Double*>(v.data);
                                break;
                            case UA_TYPES_STRING:
                                {
                                    UA_String* str = static_cast<UA_String*>(v.data);
                                    NodeList[j]["ok"] = true;
                                    NodeList[j]["val"] = std::string(reinterpret_cast<const char*>(str->data), str->length);
                                    break;
                                }
                            default:
                                NodeList[j]["ok"] = false;
                                NodeList[j]["val"] = errNotSupportedDataType;
                        }
                    } else {
                        NodeList[j]["ok"] = false;
                        NodeList[j]["val"] = errNotSupportedDataType;
                    }
                }
            }
            UA_ReadResponse_clear(&res);
            RETURN_OK(ret)
            return ret;
        }

        auto WriteBoolean(UA_UInt32 NodeId, UA_Int16 DataTypeIndex, UA_Boolean Val, sol::this_state L) {
            return doWrite(NodeId, DataTypeIndex, static_cast<void*>(&Val), L);
        }

        auto WriteInteger(UA_UInt32 NodeId, UA_Int16 DataTypeIndex, UA_Int64 Val, sol::this_state L) {
            return doWrite(NodeId, DataTypeIndex, static_cast<void*>(&Val), L);
        }

        auto WriteDouble(UA_UInt32 NodeId, UA_Int16 DataTypeIndex, UA_Double Val, sol::this_state L) {
            return doWrite(NodeId, DataTypeIndex, static_cast<void*>(&Val), L);
        }

        auto WriteFloat(UA_UInt32 NodeId, UA_Int16 DataTypeIndex, UA_Float Val, sol::this_state L) {
            return doWrite(NodeId, DataTypeIndex, static_cast<void*>(&Val), L);
        }

        auto WriteString(UA_UInt32 NodeId, UA_Int16 DataTypeIndex, const std::string& Val, sol::this_state L) {
            UA_String str = UA_STRING(const_cast<char*>(Val.data()));
            return doWrite(NodeId, DataTypeIndex, static_cast<void*>(&str), L);
        }

        auto Register(const std::string& NodeId, sol::this_state L) {
            UA_RegisterNodesRequest req;
            UA_RegisterNodesRequest_init(&req);

            UA_NodeId id = UA_NODEID_STRING(_ns, const_cast<char*>(NodeId.data()));
            req.nodesToRegister = &id;
            req.nodesToRegisterSize = 1;

            UA_RegisterNodesResponse res = UA_Client_Service_registerNodes(_client, req);
            UA_StatusCode code = res.responseHeader.serviceResult;

            sol::variadic_results ret;
            if (code == UA_STATUSCODE_GOOD) {
                if (res.registeredNodeIdsSize == 1) {
                    RETURN_OK(ret)

                    UA_UInt32 id = res.registeredNodeIds->identifier.numeric;
                    RETURN_VALUE(ret, UA_UInt32, id)

                    UA_Int16 dtidx = getNodeType(*(res.registeredNodeIds));
                    if (dtidx != -1 ) {
                        RETURN_VALUE(ret, UA_Int16, dtidx)
                        RETURN_VALUE(ret, std::string, std::string(UA_TYPES[dtidx].typeName))
                    } else {
                        RETURN_VALUE(ret, UA_Int16, dtidx)
                        RETURN_VALUE(ret, std::string, errNotSupportedDataType)
                    }

                } else {
                    RETURN_ERROR(ret, std::string(UA_StatusCode_name(UA_STATUSCODE_BADUNEXPECTEDERROR)))
                }
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }

            UA_RegisterNodesResponse_clear(&res);
            return ret;
        }

        auto UnRegister(UA_UInt32 NodeId, sol::this_state L) {
            UA_UnregisterNodesRequest req;
            UA_UnregisterNodesRequest_init(&req);

            UA_NodeId id = UA_NODEID_NUMERIC(_ns, NodeId);
            req.nodesToUnregister = &id;
            req.nodesToUnregisterSize = 1;

            UA_UnregisterNodesResponse res = UA_Client_Service_unregisterNodes(_client, req);
            UA_StatusCode code = res.responseHeader.serviceResult;

            sol::variadic_results ret;
            if (code == UA_STATUSCODE_GOOD) {
                RETURN_OK(ret)
            } else {
                RETURN_ERROR(ret, std::string(UA_StatusCode_name(code)))
            }

            UA_UnregisterNodesResponse_clear(&res);
            return ret;
        }
    };

    sol::table open(sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        module.new_usertype<Client>("client",
            sol::constructors<Client(
                const std::string&,
                const UA_MessageSecurityMode,
                const std::string&,
                const std::string&,
                const std::string&)>(),
            "connect", &Client::Connect,
            "connect_username", &Client::ConnectUsername,
            "disconnect", &Client::Disconnect,
            "read", &Client::Read,
            "write_boolean", &Client::WriteBoolean,
            "write_integer", &Client::WriteInteger,
            "write_float", &Client::WriteFloat,
            "write_double", &Client::WriteDouble,
            "write_string", &Client::WriteString,
            "register", &Client::Register,
            "unregister", &Client::UnRegister,
            "configuration", &Client::Configuration,
            "state", &Client::State
        );
        return module;
    }
}

extern "C" int luaopen_opcua(lua_State *L) {
    return sol::stack::call_lua(L, 1, opcua::open);
}
