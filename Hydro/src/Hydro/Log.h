#pragma once
#include "Core.h"

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

namespace Hydro {
	class HYDRO_API Log
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
#define HD_CORE_TRACE(...)    ::Hydro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HD_CORE_INFO(...)     ::Hydro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HD_CORE_WARN(...)     ::Hydro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HD_CORE_ERROR(...)    ::Hydro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HD_CORE_CRITICAL(...) ::Hydro::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HD_TRACE(...)         ::Hydro::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HD_INFO(...)          ::Hydro::Log::GetClientLogger()->info(__VA_ARGS__)
#define HD_WARN(...)          ::Hydro::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HD_ERROR(...)         ::Hydro::Log::GetClientLogger()->error(__VA_ARGS__)
#define HD_CRITICAL(...)      ::Hydro::Log::GetClientLogger()->critical(__VA_ARGS__)