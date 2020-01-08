#pragma once
#include <memory>

namespace SW
{
	void InitializeCore();
	void ShutdownCore();
}

//#ifdef SW_PLATFORM_WINDOWS
//	#error "Shadow Wolf only supports Windows!"
//#endif

// __VA_ARGS__ expansion to get past MSVC "bug"
#define SW_EXPAND_VARGS(x) x

#define BIT(x) (1 << x)

#define SW_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)

#include "SWAssert.h"

//pointer wrappers
namespace SW
{
	template<typename T>
		using Scope = std::unique_ptr<T>;

	template<typename T>
		using Ref = std::shared_ptr<T>;

	using byte = unsigned char;
}