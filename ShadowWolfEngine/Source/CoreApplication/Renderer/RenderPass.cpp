#include "SWpch.h"
#include "RenderPass.h"

#include "Renderer.h"

#include "Coreapplication/Platform/OpenGL/OpenGLRenderPass.h"

namespace Wolf {

	Ref<RenderPass> RenderPass::Create(const RenderPassSpecification& spec)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    SW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLRenderPass>::Create(spec);
		}

		SW_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}