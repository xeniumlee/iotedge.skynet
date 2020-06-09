#include "open62541/client_highlevel.h"
#include "open62541/client_config_default.h"

#define SOL_ALL_SAFETIES_ON 1

#ifdef CXX17
#include "sol3.hpp"
#else
#include "sol2.hpp"
#endif

namespace opcua {
    class Client {
    private:
        UA_Client* _client;
        UA_UInt16 _ns;
        UA_String _ns_name;

    private:
        auto setNamespaceIndex() {
            UA_UInt16 idx;
            UA_StatusCode ret = UA_Client_NamespaceGetIndex(_client, &_ns_name, &idx);
            if (ret == UA_STATUSCODE_GOOD) {
                _ns = idx;
            }
            return ret;
        }

    public:
        Client(const std::string& Namespace) {
            _ns_name = UA_STRING_ALLOC(Namespace.data());
            _client = UA_Client_new();
            UA_ClientConfig_setDefault(UA_Client_getConfig(_client));
        }

        ~Client() {
            UA_Client_disconnect(_client);
            UA_Client_delete(_client);
        }

        auto Connect(const std::string& EndpointUrl) {
            UA_StatusCode ret = UA_Client_connect(_client, EndpointUrl.data());
            bool ok = (ret == UA_STATUSCODE_GOOD);
            if (ok) {
                ret = setNamespaceIndex();
                ok = (ret == UA_STATUSCODE_GOOD);
                if (!ok) {
                    UA_Client_disconnect(_client);
                }
                return std::make_tuple(ok, std::string(UA_StatusCode_name(ret)));
            } else {
                return std::make_tuple(ok, std::string(UA_StatusCode_name(ret)));
            }
        }

        auto ConnectUsername(const std::string& EndpointUrl, const std::string& Username, const std::string& Password) {
            UA_StatusCode ret =  UA_Client_connect_username(_client, EndpointUrl.data(), Username.data(), Password.data());
            bool ok = (ret == UA_STATUSCODE_GOOD);
            if (ok) {
                ret = setNamespaceIndex();
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
            "register", &Client::Register,
            "unregister", &Client::UnRegister
        );
        return module;
    }
}

extern "C" int luaopen_snap7(lua_State *L) {
    return sol::stack::call_lua(L, 1, opcua::open);
}
