#pragma once

#ifdef UE_PLATFORM_WINDOWS
	#ifdef UE_BUILD_DLL
		#define UE_API __declspec(dllexport)
	#else
		#define UE_API __declspec(dllimport)
	#endif
#else
	#error Universe only supports Windows (for now)!
#endif

#define BIT(x) (1 << x)

#define UE_BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

