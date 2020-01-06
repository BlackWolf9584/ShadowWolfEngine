#include "SWpch.h"
#include "CoreApplication/Renderer/VertexArray.h"
#include "CoreApplication/Renderer/Renderer.h"
#include "CoreApplication/Platform/OpenGL/OpenGLVertexArray.h"

namespace SW
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None:    SW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		}

		SW_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
}