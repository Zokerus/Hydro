#pragma once

#ifdef HD_PLATFORM_WINDOWS
	#ifdef HD_BUILD_DLL
		#define HYDRO_API __declspec(dllexport)
	#else
		#define HYDRO_API __declspec(dllimport)
	#endif // HD_BUILD_DLL
#else
	#error Hydro only supports Windows!
#endif // HD_PLATFORM_WINDOWS

#ifdef ENABLE_ASSERTS
	#define HD_ASSERT(x, ...) {if(!(x)) {HD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreaks();}}
	#define HD_CORE_ASSERT(x, ...) {if(!(x)) {HD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreaks();}}
#else
	#define HD_ASSERT(x, ...)
	#define HD_CORE_ASSERT(x, ...)
#endif // ENABLE_ASSERTS


#define BIT(x) (1 << x)
