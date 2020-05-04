#pragma once

#ifdef HD_PLATFORM_WINDOWS
	#ifdef HD_BUILD_DLL
		#define HYDRO_API __declspec(dllexport)
	#else
		#define HYDRO_API __declspec(dllimport)
	#endif // HD_BUILD_DLL
#else
	#error HYdro only supports Windows!
#endif // HD_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
