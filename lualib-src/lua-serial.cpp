#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <linux/serial.h>

#define SOL_ALL_SAFETIES_ON 1

#ifdef CXX17
#include "sol3.hpp"
#else
#include "sol2.hpp"
#endif

namespace serial {
    class port {
    public:
        port(): fd(-1) {}
        ~port() { s_close(); }
        auto s_open(const sol::table conf) {
            const std::string& device = conf["device"];
            int parity = conf["parity"];
            int baudrate = conf["baudrate"];
            int databits = conf["databits"];
            int stopbits = conf["stopbits"];
            int r_timeout_ms = conf["r_timeout"];
            int b_timeout_us = conf["b_timeout"];
            bool rtscts = conf["rtscts"];

            int flag = O_RDWR | O_NOCTTY | O_NONBLOCK | O_EXCL;
            fd = open(device.data(), flag);
            if (fd < 0) {
                return std::make_tuple(false, error_msg("open", errno));
            }
            tcgetattr(fd, &old_tios);

            struct termios tios;
            memset(&tios, 0, sizeof(tios));
            speed_t b = serial_baudrate_to_bits(baudrate);
            cfsetispeed(&tios, b);
            cfsetospeed(&tios, b);

            tios.c_oflag = 0;
            tios.c_lflag = 0;

            if (parity != 0) {
                tios.c_iflag |= INPCK;
            }

            tios.c_cflag = CREAD | CLOCAL;
            switch (databits) {
            case 5:
                tios.c_cflag |= CS5;
                break;
            case 6:
                tios.c_cflag |= CS6;
                break;
            case 7:
                tios.c_cflag |= CS7;
                break;
            default:
                tios.c_cflag |= CS8;
                break;
            }
            if (stopbits == 2) {
                tios.c_cflag |= CSTOPB;
            }
            if (parity == 2) {
                tios.c_cflag |= PARENB;
            } else if (parity == 1) {
                tios.c_cflag |= (PARENB | PARODD);
            }
            if (rtscts) {
                tios.c_cflag |= CRTSCTS;
            }

            if (tcsetattr(fd, TCSANOW, &tios) < 0) {
                close(fd);
                return std::make_tuple(false, error_msg("tcsetattr", errno));
            }

            response_t.tv_sec = r_timeout_ms / 1000;
            response_t.tv_usec = (r_timeout_ms % 1000) * 1000;
            byte_t.tv_sec = 0;
            byte_t.tv_usec = b_timeout_us;
            return std::make_tuple(true, std::string("ok"));
        }
        void s_close() {
            if (fd != -1) {
                tcsetattr(fd, TCSANOW, &old_tios);
                close(fd);
                fd = -1;
            }
        }
        auto s_read(size_t len) {
            fd_set rfds;
            size_t bytes_left = len;
            size_t bytes_read = 0;
            struct timeval tv;
            tv.tv_sec = response_t.tv_sec;
            tv.tv_usec = response_t.tv_usec;

            int ret;
            ssize_t sz;

            void *buf = malloc(len);
            do {
                FD_ZERO(&rfds);
                FD_SET(fd, &rfds);

                if ((ret = select(fd+1, &rfds, NULL, NULL, &tv)) < 0) {
                    free(buf);
                    return std::make_tuple(false, error_msg("select", errno));
                }
                if (ret == 0) {
                    free(buf);
                    return std::make_tuple(false, error_msg("select", ETIMEDOUT));
                }
                if ((sz = read(fd, (char*)buf + bytes_read, bytes_left)) < 0) {
                    free(buf);
                    return std::make_tuple(false, error_msg("read", errno));
                }
                if (sz == 0) {
                    free(buf);
                    return std::make_tuple(false, error_msg("read", 0));
                }
                bytes_read += sz;
                bytes_left -= sz;
                if (bytes_left > 0 && tv.tv_sec == response_t.tv_sec) {
                    tv.tv_sec = byte_t.tv_sec;
                    tv.tv_usec = byte_t.tv_usec;
                }
            } while (bytes_left > 0);

            std::string s(static_cast<const char*>(buf), len);
            free(buf);
            return std::make_tuple(true, s);
        }
        auto s_write(const std::string& s) {
            ssize_t ret;
            const void *buf = static_cast<const void*>(s.data());
            if ((ret = write(fd, buf, s.size())) < 0) {
                return std::make_tuple(false, error_msg("write", errno));
            }
            if (ret == 0) {
                return std::make_tuple(false, error_msg("write", 0));
            }
            return std::make_tuple(true, std::string("ok"));
        }
    protected:
        int fd;
        struct termios old_tios;
        struct timeval response_t;
        struct timeval byte_t;

        std::string error_msg(const std::string& prefix, int error_num) {
            std::stringstream ss;
            ss << prefix << "(" << std::strerror(error_num) << ")";
            return ss.str();
        }
        speed_t serial_baudrate_to_bits(int baudrate) {
            switch (baudrate) {
                case 50: return B50;
                case 75: return B75;
                case 110: return B110;
                case 134: return B134;
                case 150: return B150;
                case 200: return B200;
                case 300: return B300;
                case 600: return B600;
                case 1200: return B1200;
                case 1800: return B1800;
                case 2400: return B2400;
                case 4800: return B4800;
                case 9600: return B9600;
                case 19200: return B19200;
                case 38400: return B38400;
#ifdef B57600
                case 57600: return B57600;
#endif
#ifdef B115200
                case 115200: return B115200;
#endif
#ifdef B230400
                case 230400: return B230400;
#endif
#ifdef B460800
                case 460800: return B460800;
#endif
#ifdef B500000
                case 500000: return B500000;
#endif
#ifdef B576000
                case 576000: return B576000;
#endif
#ifdef B921600
                case 921600: return B921600;
#endif
#ifdef B1000000
                case 1000000: return B1000000;
#endif
#ifdef B1152000
                case 1152000: return B1152000;
#endif
#ifdef B1500000
                case 1500000: return B1500000;
#endif
#ifdef B2000000
                case 2000000: return B2000000;
#endif
#ifdef B2500000
                case 2500000: return B2500000;
#endif
#ifdef B3000000
                case 3000000: return B3000000;
#endif
#ifdef B3500000
                case 3500000: return B3500000;
#endif
#ifdef B4000000
                case 4000000: return B4000000;
#endif
                default: return B9600;
            }
        }
    };
    class rs485 : public port {
    public:
        auto s_open(const sol::table conf) {
            std::tuple<bool, std::string> ret = port::s_open(conf);
            if (!std::get<0>(ret)) {
                return ret;
            }

            // https://github.com/stephane/libmodbus/issues/331
            // While the SER_RS485_RTS_ON_SEND and SER_RS485_RTS_AFTER_SEND flags are workarounds for using RTS to control an external RS485 transceiver
            struct serial_rs485 rs485conf;
            if (ioctl(fd, TIOCGRS485, &rs485conf) < 0) {
                return std::make_tuple(false, error_msg("TIOCGRS485", errno));
            }
            rs485conf.flags |= SER_RS485_ENABLED;
            if (ioctl(fd, TIOCSRS485, &rs485conf) < 0) {
                return std::make_tuple(false, error_msg("TIOCSRS485", errno));
            }
            return std::make_tuple(true, std::string("ok"));
        }
    };

    sol::table open(sol::this_state L) {
        sol::state_view lua(L);
        sol::table module = lua.create_table();

        module.new_usertype<port>("rs232",
            "open", &port::s_open,
            "close", &port::s_close,
            "read", &port::s_read,
            "write", &port::s_write
        );
        module.new_usertype<rs485>("rs485",
            "open", &rs485::s_open,
            "close", &rs485::s_close,
            "read", &rs485::s_read,
            "write", &rs485::s_write
        );
        return module;
    }
}

extern "C" int luaopen_serial(lua_State *L) {
    return sol::stack::call_lua(L, 1, serial::open);
}
