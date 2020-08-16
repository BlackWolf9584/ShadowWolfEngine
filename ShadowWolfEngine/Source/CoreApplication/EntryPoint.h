#pragma once
#include <CoreApplication\Core\Utilities\SWAssert.h>
#include <CoreApplication\Core\Utilities\Base.h>
#include <CoreApplication\Core\Application.h>

#ifdef SW_PLATFORM_WINDOWS

extern Wolf::Application* Wolf::CreateApplication();

int main(int argc, char** argv)
{
	Wolf::InitializeCore();
	Wolf::Application* app = Wolf::CreateApplication();
	SW_CORE_ASSERT(app, "Client Application is null!");
	app->Run();
	delete app;
	Wolf::ShutdownCore();
}

#endif