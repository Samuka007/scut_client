#include "socket.h"
#include <concepts>
#include <array>
#include <cstdint>
#include <coroutine>
#include <memory>

template <class T>
task<T> receiver( socket<T>& sock, T& data, std::shared_ptr<bool> consist )
{
    while( *consist )
    {
        // if data is good, read directly; 
        // otherwise, wait and give back control.
        co_await sock.async_read( data );
    }
}

void heart_beat_process_data_demo() {
    socket<int[]> a;
    int b[10];
    auto sign = std::make_shared<bool>(true);
    auto c = receiver<int[]>( a,b,sign); // call receive (1)
    
    while (true)
    {
        if ( /* data is not empty*/ true ) {
            // process data within cycle
            // timeout clear
        } else { 
            // wait a cycle
            // timeout count
        }
        c.resume();
    }
    
}

template <class T>
auto socket<T>::async_read( T& data ) {
    struct awaitable
    {
        socket& sock;
        bool receive_flag {false};
        bool await_ready() { return !sock.readable();}
        void await_suspend( task<T> h ) {
            sock.receive( data );
            h.promise().value_ = true;
            receive_flag = true;
        }
        bool await_resume() { return receive_flag; }
    };
    return awaitable{*this};
}

template <class T>
bool socket<T>::readable()
{
    // platform related implementation
};

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