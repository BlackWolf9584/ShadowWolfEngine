#include "SWpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "CoreApplication/Platform/OpenGL/OpenGLVertexArray.h"

namespace Wolf {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    SW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLVertexArray>::Create();
		}

		SW_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}