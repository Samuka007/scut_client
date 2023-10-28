// platform related

#pragma once
#include "socket.h"

#ifdef __linux__

#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <net/if.h>
#include <linux/if_packet.h>
// linux implementation
struct base_802_1x_socket
{
    base_802_1x_socket()
    : auth_8021x_sock { socket(PF_PACKET, SOCK_RAW, htons(ETH_P_PAE)) }
    {  
        int optv = 1;
        int ret {0};
        ret = setsockopt(auth_8021x_sock, SOL_SOCKET, SO_REUSEADDR, &optv, sizeof(optv));
        // check error
        if ((ret = getIfIndex(auth_8021x_sock)) < 0) {}
        bzero(&auth_8021x_addr, sizeof(auth_8021x_addr));
	    auth_8021x_addr.sll_ifindex = ret;
	    auth_8021x_addr.sll_family = PF_PACKET;
	    auth_8021x_addr.sll_protocol = htons(ETH_P_PAE);
	    auth_8021x_addr.sll_pkttype = PACKET_HOST;
    }
    bool readable();
    bool writable();
    void receive( std::span<std::byte> data );
    void send( std::span<std::byte> data );
    int auth_8021x_sock;
    struct sockaddr_ll auth_8021x_addr;
};

struct base_udp_socket
{
    
};
#endif

#ifdef __APPLE__

struct base_8021x_socket {};

#endif

#ifdef _WIN32
#endif
