#pragma once

#ifdef SLURP_PLATFORM_WINDOWS
	#ifdef SLURP_BUILD_DLL
		#define SLURP_API __declspec(dllexport)
	#else 
		#define SLURP_API __declspec(dllimport)
	#endif
#else
	#error Slurp only supports Windows
#endif