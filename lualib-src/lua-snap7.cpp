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
            int amount = DataItem["amount"];
            int wordlen = DataItem["wordlen"];
            size_t len = buffer_size(wordlen, amount);
            void *data = skynet_malloc(len);

            int ret = TS7Client::ReadArea(area, dbnumber, start, amount, wordlen, data);
            if (ret == 0) {
                std::string s(static_cast<const char*>(data), len);
                DataItem["value"] = s;
                skynet_free(data);
            } else {
                skynet_free(data);
            }
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
        }
        auto ReadMulti(sol::table DataList) {
            TS7DataItem items[MaxVars];
            size_t count = DataList.size();
            for(size_t i = 1, j = 0; j != count; i++, j++) {
                items[j].Area = DataList[i]["area"];
                items[j].DBNumber = DataList[i]["dbnumber"];
                items[j].Start = DataList[i]["start"];
                items[j].Amount = DataList[i]["amount"];
                items[j].WordLen = DataList[i]["wordlen"];
                size_t len = buffer_size(items[j].WordLen, items[j].Amount);
                DataList[i]["len"] = len;
                items[j].pdata = skynet_malloc(len);
            }

            int ret = TS7Client::ReadMultiVars(&items[0], count);
            if (ret == 0) {
                void *data;
                for(size_t i = 1, j = 0; j != count; i++, j++) {
                    data = items[j].pdata;
                    std::string s(static_cast<const char*>(data), static_cast<size_t>(DataList[i]["len"]));
                    DataList[i]["value"] = s;
                    skynet_free(data);
                }
            } else {
                for(size_t j = 0; j != count; j++) {
                    skynet_free(items[j].pdata);
                }
            }
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
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
            return info;
        }
        auto SetPDUSize(int Size) {
            int ret = TS7Client::SetParam(p_i32_PDURequest, &Size);
            bool ok = (ret == 0);
            return std::make_tuple(ok, CliErrorText(ret));
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
            "readmulti", &Cli::ReadMulti,
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
