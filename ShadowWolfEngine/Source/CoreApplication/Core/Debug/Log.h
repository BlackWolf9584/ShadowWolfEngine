#pragma once

#include "CoreApplication/Core/Utilities/Base.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Wolf {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Logging Macros
#define SW_CORE_TRACE(...)	Wolf::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SW_CORE_INFO(...)	Wolf::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SW_CORE_WARN(...)	Wolf::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SW_CORE_ERROR(...)	Wolf::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SW_CORE_FATAL(...)	Wolf::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define SW_TRACE(...)	Wolf::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SW_INFO(...)	Wolf::Log::GetClientLogger()->info(__VA_ARGS__)
#define SW_WARN(...)	Wolf::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SW_ERROR(...)	Wolf::Log::GetClientLogger()->error(__VA_ARGS__)
#define SW_FATAL(...)	Wolf::Log::GetClientLogger()->critical(__VA_ARGS__)