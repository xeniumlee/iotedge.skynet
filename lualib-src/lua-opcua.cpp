#include "open62541/client_highlevel.h"
#include "open62541/client_config_default.h"

#define SOL_ALL_SAFETIES_ON 1

#ifdef CXX17
#include "sol3.hpp"
#else
#include "sol2.hpp"
#endif

#define RETURN_VALUE(T, V) { \
	sol::variadic_results ret; \
    ret.push_back({ L, sol::in_place_type<bool>, true }); \
	ret.push_back({ L, sol::in_place_type<T>, *(T*)V.data }); \
    UA_Variant_clear(&V); \
	return ret; \
}

#define RETURN_STRING(V) { \
    UA_String* str = (UA_String*)V.data; \
	sol::variadic_results ret; \
    ret.push_back({ L, sol::in_place_type<bool>, true }); \
	ret.push_back({ L, sol::in_place_type<std::string>, std::string(reinterpret_cast<const char*>(str->data), str->length) }); \
    UA_Variant_clear(&V); \
	return ret; \
}

#define RETURN_ERROR(E, V) { \
    UA_Variant_clear(&V); \
	sol::variadic_results ret; \
    ret.push_back({ L, sol::in_place_type<bool>, false }); \
	ret.push_back({ L, sol::in_place_type<std::string>, E }); \
	return ret; \
}

namespace opcua {
    std::string err_not_supported = "Not supported data type";

    class Client {
    private:
        UA_Client* _client;
        UA_Int16 _ns = -1;

    private:
        auto setNamespaceIndex(const std::string& Namespace) {
            UA_UInt16 idx;
            UA_String ns = UA_STRING(const_cast<char*>(Namespace.data()));
            UA_StatusCode ret = UA_Client_NamespaceGetIndex(_client, &ns, &idx);
            if (ret == UA_STATUSCODE_GOOD) {
                _ns = idx;
            }
            return ret;
        }

    public:
        Client() {
            _client = UA_Client_new();
            UA_ClientConfig_setDefault(UA_Client_getConfig(_client));
        }

        ~Client() {
            UA_Client_disconnect(_client);
            UA_Client_delete(_client);
        }

        auto Connect(const std::string& EndpointUrl, const std::string& Namespace) {
            UA_StatusCode ret = UA_Client_connect(_client, EndpointUrl.data());
            bool ok = (ret == UA_STATUSCODE_GOOD);
            if (ok) {
                ret = setNamespaceIndex(Namespace);
                ok = (ret == UA_STATUSCODE_GOOD);
                if (!ok) {
                    UA_Client_disconnect(_client);
                }
                return std::make_tuple(ok, std::string(UA_StatusCode_name(ret)));
            } else {
                return std::make_tuple(ok, std::string(UA_StatusCode_name(ret)));
            }
        }

        auto ConnectUsername(const std::string& EndpointUrl, const std::string& Namespace,
                const std::string& Username, const std::string& Password) {
            UA_StatusCode ret =  UA_Client_connect_username(_client, EndpointUrl.data(), Username.data(), Password.data());
            bool ok = (ret == UA_STATUSCODE_GOOD);
            if (ok) {
                ret = setNamespaceIndex(Namespace);
                ok = (ret == UA_STATUSCODE_GOOD);
                if (!ok) {
                    UA_Client_disconnect(_client);
                }
                return std::make_tuple(ok, std::string(UA_StatusCode_name(ret)));
            } else {
                return std::make_tuple(ok, std::string(UA_StatusCode_name(ret)));
            }
        }

        auto Disconnect() {
            UA_StatusCode ret = UA_Client_disconnect(_client);
            return std::make_tuple(ret == UA_STATUSCODE_GOOD, std::string(UA_StatusCode_name(ret)));
        }

        auto Read(int NodeId, sol::this_state L) {
            UA_Variant value;
            UA_Variant_init(&value);
            const UA_NodeId nodeId = UA_NODEID_NUMERIC(_ns, NodeId);
            UA_StatusCode code = UA_Client_readValueAttribute(_client, nodeId, &value);

            if (code == UA_STATUSCODE_GOOD) {
                if (UA_Variant_isScalar(&value)) {
                    switch(value.type->typeIndex) {
                        case UA_TYPES_BOOLEAN:
                            RETURN_VALUE(UA_Boolean, value)
                        case UA_TYPES_SBYTE:
                            RETURN_VALUE(UA_SByte, value);
                        case UA_TYPES_BYTE:
                            RETURN_VALUE(UA_Byte, value);
                        case UA_TYPES_INT16:
                            RETURN_VALUE(UA_Int16, value);
                        case UA_TYPES_UINT16:
                            RETURN_VALUE(UA_UInt16, value);
                        case UA_TYPES_INT32:
                            RETURN_VALUE(UA_Int32, value);
                        case UA_TYPES_UINT32:
                            RETURN_VALUE(UA_UInt32, value);
                        case UA_TYPES_INT64:
                            RETURN_VALUE(UA_Int64, value);
                        case UA_TYPES_UINT64:
                            RETURN_VALUE(UA_UInt64, value);
                        case UA_TYPES_FLOAT:
                            RETURN_VALUE(UA_Float, value);
                        case UA_TYPES_DOUBLE:
                            RETURN_VALUE(UA_Double, value);
                        case UA_TYPES_STRING:
                            RETURN_STRING(value);
                        default:
                            RETURN_ERROR(err_not_supported, value);
                    }
                } else {
                    RETURN_ERROR(err_not_supported, value);
                }
            } else {
                RETURN_ERROR(std::string(UA_StatusCode_name(code)), value);
            }
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
            if (code == UA_STATUSCODE_GOOD && res.registeredNodeIdsSize == 1) {
                int id = res.registeredNodeIds[0].identifier.numeric;
                ret.push_back({ L, sol::in_place_type<bool>, true });
                ret.push_back({ L, sol::in_place_type<int>, id });
            } else {
                ret.push_back({ L, sol::in_place_type<bool>, false });
                ret.push_back({ L, sol::in_place_type<std::string>, std::string(UA_StatusCode_name(code)) });
            }

            UA_RegisterNodesRequest_deleteMembers(&req);
            UA_RegisterNodesResponse_deleteMembers(&res);

            return ret;
        }

        auto UnRegister(int NodeId, sol::this_state L) {
            UA_UnregisterNodesRequest req;
            UA_UnregisterNodesRequest_init(&req);

            req.nodesToUnregister = UA_NodeId_new();
            req.nodesToUnregister[0] = UA_NODEID_NUMERIC(_ns, NodeId);
            req.nodesToUnregisterSize = 1;

            UA_UnregisterNodesResponse res = UA_Client_Service_unregisterNodes(_client, req);
            UA_StatusCode code = res.responseHeader.serviceResult;

            sol::variadic_results ret;
            if (code == UA_STATUSCODE_GOOD) {
                ret.push_back({ L, sol::in_place_type<bool>, true });
            } else {
                ret.push_back({ L, sol::in_place_type<bool>, false });
                ret.push_back({ L, sol::in_place_type<std::string>, std::string(UA_StatusCode_name(code)) });
            }

            UA_UnregisterNodesRequest_deleteMembers(&req);
            UA_UnregisterNodesResponse_deleteMembers(&res);

            return ret;
        }
    };

    sol::table open(sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        module.new_usertype<Client>("client",
            "connect", sol::overload(&Client::Connect, &Client::ConnectUsername),
            "disconnect", &Client::Disconnect,
            "register", &Client::Register,
            "unregister", &Client::UnRegister
        );
        return module;
    }
}

extern "C" int luaopen_snap7(lua_State *L) {
    return sol::stack::call_lua(L, 1, opcua::open);
}
