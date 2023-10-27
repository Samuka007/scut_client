#include <boost/asio.hpp>
#include <thread>
#include <array>
#include <memory>
#include <chrono>
#include <string_view>
#include "log.h"
using namespace std::chrono_literals;
using namespace boost::asio;

// #define PF_PACKET 17
// #define ETH_P_PAE 0x888E

typedef boost::asio::generic::raw_protocol raw_protocol_t;
typedef boost::asio::generic::basic_endpoint<raw_protocol_t> raw_endpoint_t;
using sockaddr_t = boost::asio::detail::sockaddr_storage_type;
constexpr std::size_t PF_PACKET { 17 };
constexpr std::size_t ETH_P_PAE { 0x888e };

// boost::asio::ip::udp

// struct sockaddr_ll {
// 	unsigned short	sll_family;
// 	unsigned short	sll_protocol;
// 	int		sll_ifindex;
// 	unsigned short	sll_hatype;
// 	unsigned char	sll_pkttype;
// 	unsigned char	sll_halen;
// 	unsigned char	sll_addr[8];
// };

class proto_8021x : public raw_protocol_t {
public:
    proto_8021x() : raw_protocol_t( PF_PACKET, ETH_P_PAE ) {}

    typedef boost::asio::basic_raw_socket< proto_8021x > socket;
};

void some() {
    boost::asio::io_service io_service;
    proto_8021x::socket newskt( io_service,  )
}




/**
 * 
std::string ifname("eth1");

typedef boost::asio::generic::raw_protocol raw_protocol_t;
typedef boost::asio::generic::basic_endpoint<raw_protocol_t> raw_endpoint_t;

sockaddr_ll sockaddr;
memset(&sockaddr, 0, sizeof(sockaddr));
sockaddr.sll_family = PF_PACKET;
sockaddr.sll_protocol = htons(ETH_P_ALL);
sockaddr.sll_ifindex = if_nametoindex(ifname.c_str());
sockaddr.sll_hatype = 1;

raw_protocol_t::socket socket(io_service, raw_protocol_t(PF_PACKET, SOCK_RAW))
socket.bind(raw_endpoint_t(&sockaddr, sizeof(sockaddr)));
*/