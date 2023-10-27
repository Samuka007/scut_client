#include "log.h"
#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string_view>
#include <format>
using namespace std::chrono_literals;
namespace fs = std::filesystem;

constexpr std::size_t operator""_B(unsigned long long v) {
	return v;
}
constexpr std::size_t operator""_KB(unsigned long long v) {
  	return 1024u * v;
}
constexpr std::size_t operator""_MB(unsigned long long v) {
	return 1024u * 1024u * v;
}

constexpr static std::string_view LogLevelText[] =
		{ "NONE", "ERROR", "INF", "DEBUG", "TRACE" };
constexpr static std::string_view LogTypeText[] =
		{ "ALL", "INIT", "8021X", "DRCOM" };

Logger::Logger()
{
	if ( fs::exists ( logPath ) ){
		if ( fs::file_size( logPath ) > 100_KB ) {
			replaceOld();
		}
	}
	try {
	file_d.open( logPath, std::ios::app );
	} catch ( std::exception& e ) {
		std::cout 
			<< std::format( "Couldn't open file {}: {}", logPath, e.what() )
			<< std::endl;
	}
}

void Logger::replaceOld() noexcept {
	if ( fs::exists ( oldPath ) ) {
		try { fs::remove (oldPath); }
		catch ( fs::filesystem_error& e ) {
			std::cout 
				<< std::format( "Couldn't remove file {}: {}", oldPath, e.what() )
				<< std::endl;
		} 
	}
	try { 
		fs::copy_file( logPath, oldPath );
		fs::remove ( logPath );
	}
	catch ( fs::filesystem_error& e ) {
		std::cout
			<< std::format( "Couldn't move old file: {}", e.what() )
			<< std::endl;
	}
}

void Logger::log( Type type, Level level, auto&&...args ) 
{
    file_d << std::format("{} {} {} {}\n",
		std::chrono::system_clock::now(),
		LogTypeText[type],
		LogLevelText[level],
		std::format( args... )
	);
}
