#include "snap7.h"
#include "skynet_malloc.h"
#define SOL_ALL_SAFETIES_ON 1

#ifdef CXX17
#include "sol3.hpp"
#else
#include "sol2.hpp"
#endif

namespace snap7 {
    class Cli: public TS7Client {
    public:
        auto ConnectTo(const std::string& RemAddress, int Rack, int Slot) {
            int ret = TS7Client::ConnectTo(RemAddress.data(), Rack, Slot);
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
        }
        auto Connect() {
            int ret = TS7Client::Connect();
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
        }
        auto Disconnect() {
            int ret = TS7Client::Disconnect();
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
        }
        auto Read(sol::table DataItem) {
            int area = DataItem["area"];
            int dbnumber = DataItem["dbnumber"];
            int start = DataItem["start"];
            int amount = DataItem["number"];
            int wordlen = DataItem["wordlen"];
            size_t len = DataItem["len"];
            void *data = skynet_malloc(len);

            int ret = TS7Client::ReadArea(area, dbnumber, start, amount, wordlen, data);
            if (ret == 0) {
                std::string s(static_cast<const char*>(data), len);
                skynet_free(data);
                return std::make_tuple(true, s);
            } else {
                skynet_free(data);
                return std::make_tuple(false, CliErrorText(ret));
            }
        }
        auto Write(const sol::table DataItem) {
            int area = DataItem["area"];
            int dbnumber = DataItem["dbnumber"];
            int start = DataItem["start"];
            int amount = DataItem["number"];
            int wordlen = DataItem["wordlen"];
            std::string s = DataItem["data"];
            void *data = const_cast<void*>(static_cast<const void*>(s.data()));

            int ret = TS7Client::WriteArea(area, dbnumber, start, amount, wordlen, data);
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
        }
        auto Info(sol::this_state L) {
            sol::state_view lua(L);
            sol::table info = lua.create_table();
            info["exectime"] = TS7Client::ExecTime();
            info["lasterror"] = CliErrorText(TS7Client::LastError());
            info["pdurequested"] = TS7Client::PDURequested();
            info["pdulength"] = TS7Client::PDULength();
            info["plcstatus"] = plc_status(TS7Client::PlcStatus());

            int value, ret;
            ret = TS7Client::GetParam(3, &value);
            if (ret == 0) {
                info["pingtimeout"] = value;
            }

            ret = TS7Client::GetParam(4, &value);
            if (ret == 0) {
                info["sendtimeout"] = value;
            }

            ret = TS7Client::GetParam(5, &value);
            if (ret == 0) {
                info["recvtimeout"] = value;
            }

            ret = TS7Client::GetParam(6, &value);
            if (ret == 0) {
                info["workinterval"] = value;
            }
            return info;
        }
    private:
        std::string plc_status(int status) {
            switch (status)
            {
              case S7CpuStatusRun:
                  return "Running";
              case S7CpuStatusStop:
                  return "Stopped";
              default:
                  return "Unknown";
            }
        }
    };

    sol::table open(sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        module.new_usertype<Cli>("client",
            "connect", &Cli::Connect,
            "connectto", &Cli::ConnectTo,
            "disconnect", &Cli::Disconnect,
            "connected", &Cli::Connected,
            "read", &Cli::Read,
            "write", &Cli::Write,
            "info", &Cli::Info
        );
        return module;
    }
}

extern "C" int luaopen_snap7(lua_State *L) {
    return sol::stack::call_lua(L, 1, snap7::open);
}
