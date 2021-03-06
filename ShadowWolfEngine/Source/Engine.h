//
// Note:	this file is to be included in client applications ONLY
//			NEVER include this file anywhere in the engine codebase
//
#pragma once

//Engine Includes
#include "CoreApplication/Core/Application.h"
#include "CoreApplication/Core/Debug/Log.h"
#include "CoreApplication/Core/Utilities/Timer.h"
#include "CoreApplication/Core/Utilities/TimeStep.h"
#include "CoreApplication/Core/InputCore/Input.h"

#include "CoreApplication/Core/Events/ApplicationEvent.h"
#include "CoreApplication/Core/Events/Event.h"
#include "CoreApplication/Core/Events/KeyEvent.h"
#include "CoreApplication/Core/Events/MouseEvent.h"

//Math
#include "CoreApplication/Core/Math/AABB.h"
#include "CoreApplication/Core/Math/Ray.h"

//#include <imgui.h>
#include "../Dependencies/ImGui/imgui.h"

//Renderer API includes
#include "CoreApplication/Renderer/Renderer.h"
#include "CoreApplication/Renderer/Framebuffer.h"
#include "CoreApplication/Renderer/Buffer.h"
#include "CoreApplication/Renderer/VertexArray.h"
#include "CoreApplication/Renderer/Texture.h"
#include "CoreApplication/Renderer/Shader.h"
#include "CoreApplication/Renderer/Mesh.h"
#include "CoreApplication/Renderer/Camera.h"
#include "CoreApplication/Renderer/Material.h"
#include "CoreApplication/Renderer/SceneRenderer.h"
#include "CoreApplication/Renderer/RenderPass.h"

//Scene Includes
#include "CoreApplication/Scene/Components.h"
#include "CoreApplication/Scene/Entity.h"
#include "CoreApplication/Scene/Scene.h"
#include "CoreApplication/Scene/SceneCamera.h"
#include "CoreApplication/Scene/SceneSerializer.h"