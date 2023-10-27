#include "socket.h"
#include <concepts>
#include <array>
#include <coroutine>
#include <memory>

template <Socket T>
inline bool socket<T>::readable() { return impl_->readable(); }

template <Socket T>
auto socket<T>::async_read( std::span<std::byte> data )
{
    struct awaiter
    {
        socket& sock;
        bool flag {false};
        bool await_ready() { return !sock.readable(); }
        void await_suspend( std::coroutine_handle<> h )
        {
            sock.impl_->receive( data );
            flag = true;
        }
        bool await_resume() { return flag; }
    };
    return awaiter{ *this };
}

template <Socket T>
auto socket<T>::async_write( std::span<std::byte> data )
{
    struct awaiter
    {
        socket& sock;
        bool flag {false};
        bool await_ready() { return !sock.readable(); }
        void await_suspend( std::coroutine_handle<> h )
        {
            sock.impl_->send( data );
            flag = true;
        }
        bool await_resume() { return flag; }
    };
    return awaiter{ *this };
}

// implement below related to plaform


