#pragma once

#ifdef UE_DEBUG
	#define UE_ENABLE_ASSERTS
#endif

#define BIT(x) (1 << x)

#define UE_BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

