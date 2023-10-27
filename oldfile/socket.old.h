#pragma once
#include <concepts>
#include <array>
#include <cstdint>
#include <coroutine>
#include <memory>
// #include <future>

template <class T>
struct promise
{
    T value_;
    task get_return_object() { return{}; }
    std::suspend_never initail_suspend() { return {}; }
    std::suspend_never final_suspend() { return {}; }
    void return_void() {}
    void unhandled_exception() {}
    template <std::convertible_to<T> From>
    std::suspend_always yield_value( From&& from )
    {
        value_ = std::forward<From> (from);
        return {};
    }
    void return_void() {};
};

template <typename T>
struct task : std::coroutine_handle<promise<T>>
{ using promise_type = ::promise<T>; };

// template <class socket_t>
// requires requires( socket_t socket ) { socket.async_read(); }
// class receiver
// {
//     task receive();
// };

// 
// template <class T>
// task<T> receive( socket<T> sock, auto& data );

// task send()

class protocol;

template < class data_t >
// require data_t has member data()
class socket {
    class impl;
    std::unique_ptr<impl> impl_p;
public:
static constexpr std::size_t		ETH_FRAME_LEN			{ 1514 };
    // typedef protocol_type 
    

    socket();
    auto async_read( data_t& data ); // awaitable
    task<data_t> async_write( data_t& data ); // awaitable

    bool readable();
    void receive( data_t& data );

private:
    
};



class msg_handler {


};
