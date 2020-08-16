#include "Engine.h"
#include "CoreApplication/EntryPoint.h"
#include "EditorLayer.h"

class SWApplication : public Wolf::Application
{
public: 
	SWApplication(const Wolf::ApplicationProps& props)
		: Application(props)
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new Wolf::EditorLayer());
	}
};

Wolf::Application* Wolf::CreateApplication()
{
	return new SWApplication({ "Playground", 1600, 900 });
}