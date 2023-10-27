#pragma once
#include <concepts>
#include <array>
#include <cstdint>
#include <coroutine>
#include <memory>

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

// template <class socket_t>
// requires requires( socket_t socket ) { socket.async_read(); }
// class receiver
// {
//     task receive();
// };

// 
task receive( socket sock, auto& data );

// task send()

class protocol;

class socket {
    class impl;
    std::unique_ptr<impl> impl_p;
public:
static constexpr std::size_t		ETH_FRAME_LEN			{ 1514 };
    // typedef protocol_type 
    socket();
    task async_read( auto& data );
    task async_write( auto& data );
private:
    
};



class msg_handler {


};
