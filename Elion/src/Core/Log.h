#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Elion
{


	class ELION_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_ClientLogger; }
	};

}

#define ELION_CORE_ERROR(...)      ::Elion::Log::get_core_logger()->error(__VA_ARGS__)
#define ELION_CORE_INFO(...)       ::Elion::Log::get_core_logger()->info(__VA_ARGS__)
#define ELION_CORE_TRACE(...)      ::Elion::Log::get_core_logger()->trace(__VA_ARGS__)
#define ELION_CORE_WARN(...)       ::Elion::Log::get_core_logger()->warn(__VA_ARGS__)
#define ELION_CORE_FATAL(...)      ::Elion::Log::get_core_logger()->fatal(__VA_ARGS__)



#define ELION_ERROR(...)           ::Elion::Log::get_client_logger()->error(__VA_ARGS__)
#define ELION_INFO(...)            ::Elion::Log::get_client_logger()->info(__VA_ARGS__)
#define ELION_TRACE(...)           ::Elion::Log::get_client_logger()->trace(__VA_ARGS__)
#define ELION_WARN(...)            ::Elion::Log::get_client_logger()->warn(__VA_ARGS__)
#define ELION_FATAL(...)           ::Elion::Log::get_client_logger()->fatal(__VA_ARGS__)