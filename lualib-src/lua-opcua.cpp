#include "open62541/types_generated_handling.h"
#include "open62541/client.h"

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
    public:
        auto Register(int NsIndex, const std::string& NodeId, sol::this_state L) {
            UA_RegisterNodesRequest req;
            UA_RegisterNodesRequest_init(&req);

            req.nodesToRegister = UA_NodeId_new();
            req.nodesToRegister[0] = UA_NODEID_STRING_ALLOC(NsIndex, NodeId.data());
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
        auto UnRegister(int NsIndex, int NodeId, sol::this_state L) {
            UA_UnregisterNodesRequest req;
            UA_UnregisterNodesRequest_init(&req);

            req.nodesToUnregister = UA_NodeId_new();
            req.nodesToUnregister[0] = UA_NODEID_NUMERIC(NsIndex, NodeId);
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
        }
    };

    sol::table open(sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        module.new_usertype<Client>("client",
            "register", &Client::Register,
            "unregister", &Client::UnRegister
        );
        return module;
    }
}

extern "C" int luaopen_snap7(lua_State *L) {
    return sol::stack::call_lua(L, 1, opcua::open);
}
