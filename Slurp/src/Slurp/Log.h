#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Slurp
{
	class SLURP_API Log
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

// Core log macros
#define SLURP_CORE_TRACE(...) ::Slurp::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SLURP_CORE_INFO(...)  ::Slurp::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SLURP_CORE_WARN(...)  ::Slurp::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SLURP_CORE_ERROR(...) ::Slurp::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SLURP_CORE_FATAL(...) ::Slurp::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SLURP_TRACE(...)      ::Slurp::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SLURP_INFO(...)       ::Slurp::Log::GetClientLogger()->info(__VA_ARGS__)
#define SLURP_WARN(...)       ::Slurp::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SLURP_ERROR(...)      ::Slurp::Log::GetClientLogger()->error(__VA_ARGS__)
#define SLURP_FATAL(...)      ::Slurp::Log::GetClientLogger()->fatal(__VA_ARGS__)