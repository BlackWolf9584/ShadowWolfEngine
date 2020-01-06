#pragma once
#include "CoreApplication/Core/Utilities/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/logger.h>
#include <spdlog/fmt/ostr.h>

namespace SW
{
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

//Core logging macros
#define SW_CORE_TRACE(...)	SW::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SW_CORE_INFO(...)	SW::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SW_CORE_WARN(...)	SW::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SW_CORE_ERROR(...)	SW::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SW_CORE_FATAL(...)	SW::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define SW_TRACE(...)	SW::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SW_INFO(...)	SW::Log::GetClientLogger()->info(__VA_ARGS__)
#define SW_WARN(...)	SW::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SW_ERROR(...)	SW::Log::GetClientLogger()->error(__VA_ARGS__)
#define SW_FATAL(...)	SW::Log::GetClientLogger()->critical(__VA_ARGS__)