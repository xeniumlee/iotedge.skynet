#include "snap7.h"
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
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        auto Connect() {
            int ret = TS7Client::Connect();
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        auto Disconnect() {
            int ret = TS7Client::Disconnect();
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        auto Read(const sol::table DataItem) {
            int area = DataItem["area"];
            int dbnumber = DataItem["dbnumber"];
            int start = DataItem["start"];
            int amount = DataItem["amount"];
            int wordlen = DataItem["wordlen"];
            size_t len = buffer_size(wordlen, amount);
            void *data = malloc(len);

            int ret = TS7Client::ReadArea(area, dbnumber, start, amount, wordlen, data);
            if (ret == 0) {
                std::string s(static_cast<const char*>(data), len);
                free(data);
                return std::make_tuple(true, s);
            } else {
                free(data);
                return std::make_tuple(false, CliErrorText(ret));
            }
        }
        auto Write(const sol::table DataItem) {
            int area = DataItem["area"];
            int dbnumber = DataItem["dbnumber"];
            int start = DataItem["start"];
            int amount = DataItem["amount"];
            int wordlen = DataItem["wordlen"];
            std::string s = DataItem["data"];
            void *data = const_cast<void*>(static_cast<const void*>(s.data()));

            int ret = TS7Client::WriteArea(area, dbnumber, start, amount, wordlen, data);
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        auto Info(sol::this_state L) {
            sol::state_view lua(L);
            sol::table info = lua.create_table();
            info["exectime"] = TS7Client::ExecTime();
            info["lasterror"] = CliErrorText(TS7Client::LastError());
            info["pdurequested"] = TS7Client::PDURequested();
            info["pdulength"] = TS7Client::PDULength();
            info["plcstatus"] = plc_status(TS7Client::PlcStatus());
            return info;
        }
        auto SetPDUSize(int Size) {
            int ret = TS7Client::SetParam(p_i32_PDURequest, &Size);
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        /*
        auto ClearPassword() {
            int ret = TS7Client::ClearSessionPassword();
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        auto SetPassword(const std::string& Password) {
            int ret = TS7Client::SetSessionPassword(const_cast<char*>(Password.data()));
            bool b = (ret == 0);
            return std::make_tuple(b, CliErrorText(ret));
        }
        */
    private:
        size_t buffer_size(int wordlen, int amount) {
            switch (wordlen)
            {
              case S7WLBit:
              case S7WLByte:
                  return 1 * amount;
              case S7WLWord:
              case S7WLCounter:
              case S7WLTimer:
                  return 2 * amount;
              case S7WLDWord:
              case S7WLReal:
                  return 4 * amount;
              default:
                  return 1 * amount;
            }
        }
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
            "info", &Cli::Info,
            "setpdusize", &Cli::SetPDUSize
            //"setpassword", sol::overload(&Cli::SetPassword, &Cli::ClearPassword)
        );
        return module;
    }
}

extern "C" int luaopen_snap7(lua_State *L) {
    return sol::stack::call_lua(L, 1, snap7::open);
}
