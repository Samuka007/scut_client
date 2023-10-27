#pragma once

#include <concepts>
// #include <array>
#include <coroutine>
#include <memory>
#include <span>

template < typename Ty >
concept Socket 
    = requires ( Ty sock, std::span<std::byte> data )
    {
        sock.receive( data );
        sock.send( data );
        sock.readable();
        sock.writable();
    };

template < Socket Impl >
class socket
{
struct task
{ 
    struct promise_type
    {
        task get_return_object() { return{}; }
        std::suspend_never initail_suspend() { return {}; }
        std::suspend_never final_suspend() { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    }; 
};

public:
    socket( auto&&... args )
    : impl_( std::forward<decltype(args)>(args)... ) {}
    auto async_read( std::span<std::byte> data );
    auto async_write( std::span<std::byte> data );
    bool readable();
private:
    std::unique_ptr<Impl> impl_;
};
