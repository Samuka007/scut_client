#include "socket.h"
#include <concepts>
#include <array>
#include <cstdint>
#include <coroutine>
#include <memory>



task socket::async_read( auto& data ) {

}

#if 1

#endif

#if 0
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

class socket::impl {
public:
    bool await_ready() { }

private:
    
};

#endif