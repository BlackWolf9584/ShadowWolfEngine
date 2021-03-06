#pragma once

#include <memory>
#include "Ref.h"

namespace Wolf {

	void InitializeCore();
	void ShutdownCore();

}

#ifndef SW_PLATFORM_WINDOWS
	#error Shadow Wolf only supports Windows!
#endif

// __VA_ARGS__ expansion to get past MSVC "bug"
#define SW_EXPAND_VARGS(x) x

#define BIT(x) (1 << x)

#define SW_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)

#include "SWAssert.h"

// Pointer wrappers
namespace Wolf {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	using byte = uint8_t;

}