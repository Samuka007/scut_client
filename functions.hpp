// Hex Generator

#include <vector>
#include <cstdint>
#include <string_view>
#include <cstring>
// #include "log.hpp"
#include <span>
#include <array>
#include "md5.h"
// #include <future>

using package = std::vector<uint8_t>;

class HexFactory {
public:
    HexFactory( uint8_t id, std::string_view password, std::span<const uint8_t, 16> srcMD5 )
    :   m_id( id ),
        m_passwd( password ),
        m_md5( srcMD5 ) {} //input meterials

    static constexpr auto msg_size = 128u;
    static constexpr auto hex_size = 16u;

    HexFactory& process() {
        std::array<uint8_t, msg_size> msgbuf{}; // msgbuf = ‘id‘ + ‘passwd’ + ‘srcMD5’
        md5_state_t md5_msg;
        md5_init(&md5_msg);

        auto passlen = m_passwd.size();
        auto msglen = sizeof(m_id) + passlen + m_md5.size_bytes();

        msgbuf[0] = m_id;
        std::memcpy(msgbuf.data() + sizeof(m_id), m_passwd.data(), m_passwd.size());
        std::memcpy(msgbuf.data() + sizeof(m_id) + passlen, m_md5.data(), m_md5.size_bytes());

        md5_append(&md5_msg, msgbuf.data(), msglen);
        result.resize( hex_size );
        md5_finish(&md5_msg, result.data());
        return *this;
    }

    package get_copy() {
        return result;
    }

    auto move() {
        return std::move(result);
    }

    // void printHex() {
    //     logg::log( warning, "something" );
    // }

private:
    const uint8_t m_id;
    const std::string_view m_passwd;
    const std::span<const uint8_t, 16> m_md5;
    package result;
};

int hexStrToByte(const char* source, unsigned char* dest, int bufLen) {
	int i;
	unsigned char highByte, lowByte;

	for (i = 0; source[i * 2] && source[i * 2 + 1] && (i < bufLen); i++) {
		highByte = toupper(source[i * 2]);
		lowByte = toupper(source[i * 2 + 1]);

		if (highByte > 0x39) {
			highByte -= 0x37;
		} else {
			highByte -= 0x30;
		}

		if (lowByte > 0x39) {
			lowByte -= 0x37;
		} else {
			lowByte -= 0x30;
		}

		dest[i] = (highByte << 4) | lowByte;
	}
	return i;
}
