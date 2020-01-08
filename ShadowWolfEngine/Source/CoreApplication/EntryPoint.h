#pragma once
#include <CoreApplication\Core\Utilities\SWAssert.h>
#include <CoreApplication\Core\Utilities\Base.h>
#include <CoreApplication\Core\Application.h>

#ifdef SW_PLATFORM_WINDOWS

extern SW::Application* SW::CreateApplication();

int main(int argc, char** argv)
{
	SW::InitializeCore();
	SW::Application* app = SW::CreateApplication();
	SW_CORE_ASSERT(app, "Client Application is null!");
	app->Run();
	delete app;
	SW::ShutdownCore();
}

#endif