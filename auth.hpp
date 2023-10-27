// #include <boost/asio.hpp>
#include <thread>
#include <array>
#include <memory>
#include <chrono>
#include <string_view>
#include "log.h"
using namespace std::chrono_literals;
// using namespace boost::asio;

// 1. Init 802.1x socket
// 2. Init Headers
// 3. sent 802.1x Log off, twice
// 	3.1 
// 4. 


class Authentication {
public:
static constexpr std::string_view 	DEFAULT_SERVER_ADDR 	{ "202.38.210.131" };
static constexpr std::string_view 	DEFAULT_DNS_ADDR		{ "222.201.130.30" };
static constexpr std::size_t		DEFAULT_SERVER_PORT 	{ 61440 };
static constexpr std::size_t		ETH_FRAME_LEN			{ 1514 };
static constexpr std::size_t        ETH_P_PAE               { 0x888e };

const std::string_view 	SERVER_ADDR { DEFAULT_SERVER_ADDR };
const std::string_view	DNS_ADDR	{ DEFAULT_DNS_ADDR };
const std::size_t		SERVER_PORT { DEFAULT_SERVER_PORT };

enum class LOG_STATUS { LOGIN, LOGOFF };

class socket_8021x {
public:
private:
	// receive
	// sent
	// handle
	std::array<std::byte, ETH_FRAME_LEN> data;

};

class socket_udp {
public:
private:
	// receive
	// sent
	// handle
	std::array<std::byte, ETH_FRAME_LEN> data;
};

	Authentication ( LOG_STATUS status, std::shared_ptr<Logger> lg ) 
	: 	status(status), 
		logger(lg) {}

private:
	LOG_STATUS status;
	std::shared_ptr<Logger> logger;
	// ip::udp::socket skt;
};






















// struct in_addr local_ipaddr;
// uint8_t MAC[6];

// #define DRCOM_UDP_HEARTBEAT_DELAY  12 // Drcom客户端心跳延时秒数，默认12秒
// #define DRCOM_UDP_HEARTBEAT_TIMEOUT 2 // Drcom客户端心跳超时秒数
// #define DRCOM_UDP_RECV_DELAY  2 // Drcom客户端收UDP报文延时秒数，默认2秒
// #define AUTH_8021X_LOGOFF_DELAY 500000 // 客户端退出登录收包等待时间 0.5秒（50万微秒)
// #define AUTH_8021X_RECV_DELAY  1 // 客户端收8021x报文延时秒数，默认1秒
// #define AUTH_8021X_RECV_TIMES  3 // 客户端收8021x报文重试次数

// /* 静态常量*/
// const static uint8_t BroadcastAddr[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }; // 广播MAC地址
// const static uint8_t MultcastAddr[6] = { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x03 }; // 多播MAC地址
// const static uint8_t UnicastAddr[6] = { 0x01, 0xd0, 0xf8, 0x00, 0x00, 0x03 }; // 单播MAC地址

// /* 静态变量*/
// static uint8_t send_8021x_data[1024]; // 用于存放发送8021x报文的变量
// static size_t send_8021x_data_len = 0; // 用于存放发送8021x报文的变量的长度
// static uint8_t send_udp_data[ETH_FRAME_LEN];
// static uint8_t recv_udp_data[ETH_FRAME_LEN];
// static int send_udp_data_len = 0; // 用于存放发送udp报文的变量的长度
// static int resev = 0; // 是否收到了第一帧报文的标志位，第一帧报文用于拿到服务器的mac
// static int times = AUTH_8021X_RECV_TIMES; // 8021x断链重试次数
// static int success_8021x = 0; // 8021x成功登录标志位
// static int isNeedHeartBeat = 0;  // 是否需要发送UDP心跳
// static uint8_t EthHeader[14] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 		0x00, 0x00, 0x00, 0x00, 0x88, 0x8e };
// static uint8_t BroadcastHeader[14] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
// 		0xff, 0xff, 0xff, 0xff, 0xff, 0x88, 0x8e };
// static uint8_t MultcastHeader[14] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
// 		0x80, 0xc2, 0x00, 0x00, 0x03, 0x88, 0x8e };
// static uint8_t UnicastHeader[14] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
// 		0xd0, 0xf8, 0x00, 0x00, 0x03, 0x88, 0x8e };
// // static time_t BaseHeartbeatTime = 0;  // UDP心跳基线时间
// static const std::chrono::duration<std::chrono::seconds> = 0s;
// static int auth_8021x_sock = 0; // 8021x的socket描述符
// static int auth_udp_sock = 0; // udp的socket描述符
// static uint8_t lastHBDone = 1;	// 记录上次心跳是否成功结束，没有的话重拨
// struct sockaddr_ll auth_8021x_addr;

// /* 静态变量*/

// enum EAP_Code {
// 	REQUEST = 1, RESPONSE = 2, SUCCESS = 3, FAILURE = 4, H3CDATA = 10
// };
// enum EAP_Type {
// 	IDENTITY = 1,
// 	NOTIFICATION = 2,
// 	MD5 = 4,
// 	AVAILABLE = 20,
// 	ALLOCATED_0x07 = 7,
// 	ALLOCATED_0x08 = 8
// };
// typedef uint8_t EAP_ID;
// struct sockaddr_in serv_addr, local_addr;

// class call : ip::udp::socket {
// 	// call() : ip::udp::socket( )
// };

// typedef enum {MISC_START_ALIVE=0x01, MISC_RESPONSE_FOR_ALIVE=0x02, MISC_INFO=0x03, MISC_RESPONSE_INFO=0x04, MISC_HEART_BEAT=0x0b, MISC_RESPONSE_HEART_BEAT=0x06} DRCOM_Type;
// typedef enum {MISC_HEART_BEAT_01_TYPE=0x01, MISC_HEART_BEAT_02_TYPE=0x02, MISC_HEART_BEAT_03_TYPE=0x03, MISC_HEART_BEAT_04_TYPE=0x04, MISC_FILE_TYPE=0x06} DRCOM_MISC_HEART_BEAT_Type;

// int Drcom_UDP_Handler(uint8_t *recv_data) {
// 	int data_len = 0;
// 	if (recv_data[0] == 0x07) {
// 		// 根据收到的recv_data，填充相应的send_udp_data
// 		switch ((DRCOM_Type) recv_data[4]) {
// 		case MISC_RESPONSE_FOR_ALIVE:
// 			// 一秒后才回复
// 			// sleep(1);
// 			std::this_thread::sleep_for(1s);
// 			//ALIVE已经回复，关闭心跳计时
// 			isNeedHeartBeat = 0;
// 			BaseHeartbeatTime = time(NULL);
// 			lastHBDone = 1;
// 			data_len = Drcom_MISC_INFO_Setter(send_udp_data, recv_data);
// 			LogWrite(DRCOM, INF,"Server: MISC_RESPONSE_FOR_ALIVE. Send MISC_INFO.");
// 			break;
// 		case MISC_RESPONSE_INFO:
// 			// 存好tail信息，并顺便解密，以备后面udp报文使用
// 			memcpy(tailinfo, recv_data + 16, 16);
// 			encryptDrcomInfo(tailinfo);
// 			data_len = Drcom_MISC_HEART_BEAT_01_TYPE_Setter(send_udp_data, recv_data);
// 			isNeedHeartBeat = 1;
// 			LogWrite(DRCOM, INF, "Server: MISC_RESPONSE_INFO. Send MISC_HEART_BEAT_01.");
// 			break;
// 		case MISC_HEART_BEAT:
// 			switch ((DRCOM_MISC_HEART_BEAT_Type) recv_data[5]) {
// 			case MISC_FILE_TYPE:
// 				data_len = Drcom_MISC_HEART_BEAT_01_TYPE_Setter(send_udp_data, recv_data);
// 				LogWrite(DRCOM, INF, "Server: MISC_FILE_TYPE. Send MISC_HEART_BEAT_01.");
// 				break;
// 			case MISC_HEART_BEAT_02_TYPE:
// 				data_len = Drcom_MISC_HEART_BEAT_03_TYPE_Setter(send_udp_data, recv_data);
// 				LogWrite(DRCOM, INF, "Server: MISC_HEART_BEAT_02. Send MISC_HEART_BEAT_03.");
// 				break;
// 			case MISC_HEART_BEAT_04_TYPE:
// 				// 收到这个包代表完成一次心跳流程，这里要初始化时间基线，开始计时下次心跳
// 				BaseHeartbeatTime = time(NULL);
// 				lastHBDone = 1;
// 				LogWrite(DRCOM, INF, "Server: MISC_HEART_BEAT_04. Waiting next heart beat cycle.");
// 				break;
// 			default:
// 				LogWrite(DRCOM, ERROR, "Server: Unexpected heart beat request (type:0x%02hhx)!",
// 						recv_data[5]);
// 				break;
// 			}
// 			break;
// 		case MISC_RESPONSE_HEART_BEAT:
// 			data_len = Drcom_MISC_HEART_BEAT_01_TYPE_Setter(send_udp_data, recv_data);
// 			LogWrite(DRCOM, INF, "Server: MISC_RESPONSE_HEART_BEAT. Send MISC_HEART_BEAT_01.");
// 			break;
// 		default:
// 			LogWrite(DRCOM, ERROR, "UDP Server: Unexpected request (type:0x%02hhx)!",
// 					recv_data[2]);
// 			break;
// 		}
// 	}

// 	// Message, Server information
// 	if ((recv_data[0] == 0x4d) && (recv_data[1] == 0x38)) {
// 		LogWrite(DRCOM, INF, "%s%s", "Server: Server Information: ", recv_data + 4);
// 	}
// 	memset(recv_data, 0, ETH_FRAME_LEN);
// 	return data_len;
// }

// void dosome() {
//     io_context io_context;
//     ip::udp::socket socket(io_context, ip::udp::endpoint(ip::udp::v4(), PORT_NUMBER));

//     while (true) {
//         boost::asio::ip::udp::endpoint sender_endpoint;
//         char recv_udp_data[1024];
//         size_t length = socket.receive_from(boost::asio::buffer(recv_udp_data, 1024), sender_endpoint);

//         if (length > 0) {
//             // Handle received data
//             char send_udp_data[1024];
//             size_t send_udp_data_len = 0;

//             // TODO: Implement Drcom_UDP_Handler and Drcom_ALIVE_HEARTBEAT_TYPE_Setter functions

//             send_udp_data_len = Drcom_UDP_Handler(recv_udp_data);
//             if (success_8021x && send_udp_data_len) {
//                 socket.send_to(boost::asio::buffer(send_udp_data, send_udp_data_len), sender_endpoint);
//             }
//         }

//         // TODO: Implement heartbeat logic
//     }
// }