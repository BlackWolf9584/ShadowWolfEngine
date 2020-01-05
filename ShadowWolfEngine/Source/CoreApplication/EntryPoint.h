#pragma once

#ifdef SW_PLATFORM_WINDOWS

extern SW::Application* SW::CreateApplication();

int main(int argc, char** argv)
{
	SW::InitializeCore();
	SW::Application* app = SW::CreateApplication();
	app->Run();
	delete app;
	SW::ShutdownCore();
}

#endif