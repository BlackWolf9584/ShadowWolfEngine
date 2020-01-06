#include "SWpch.h"
#include "Base.h"
#include "Debug/Log.h"

#define SW_BUILD_ID "v0.1a"

namespace SW
{
	void InitializeCore()
	{
		SW::Log::Init();

		SW_CORE_TRACE("Shadow Wolf Engine {}", SW_BUILD_ID);
		SW_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		SW_CORE_TRACE("Shutting down...");
	}
}