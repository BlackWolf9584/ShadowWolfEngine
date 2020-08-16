#include "SWpch.h"
#include "Base.h"

#include "CoreApplication/Core/Debug/Log.h"

#define WOLF_BUILD_ID "v0.1a"

namespace Wolf
{

	void InitializeCore()
	{
		Log::Init();

		SW_CORE_TRACE("Shadow Wolf Engine {}", WOLF_BUILD_ID);
		SW_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		SW_CORE_TRACE("Shutting down...");
	}

}