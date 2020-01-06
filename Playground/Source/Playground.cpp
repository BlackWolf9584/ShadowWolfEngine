#include "Engine.h"
#include "CoreApplication/EntryPoint.h"
#include "EditorLayer.h"

class SWApplication : public SW::Application
{
public: 
	SWApplication(const SW::ApplicationProps& props)
		: Application(props)
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new SW::EditorLayer());
	}
};

SW::Application* SW::CreateApplication()
{
	return new SWApplication({ "Playground", 1600, 900 });
}