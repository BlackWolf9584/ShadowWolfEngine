#include "SWpch.h"
#include "ScriptEngineRegistry.h"
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CoreApplication/Scene/Entity.h"
#include "ScriptWrappers.h"
#include <iostream>

namespace Wolf
{
	std::unordered_map<MonoType*, std::function<bool(Entity&)>> s_HasComponentFuncs;
	std::unordered_map<MonoType*, std::function<void(Entity&)>> s_CreateComponentFuncs;

	extern MonoImage* s_CoreAssemblyImage;

#define Component_RegisterType(Type) \
	{\
		MonoType* type = mono_reflection_type_from_name("Wolf." #Type, s_CoreAssemblyImage);\
		if (type) {\
			uint32_t id = mono_type_get_type(type);\
			s_HasComponentFuncs[type] = [](Entity& entity) { return entity.HasComponent<Type>(); };\
			s_CreateComponentFuncs[type] = [](Entity& entity) { entity.AddComponent<Type>(); };\
		} else {\
			SW_CORE_ERROR("No C# component class found for " #Type "!");\
		}\
	}

	static void InitComponentTypes()
	{
		Component_RegisterType(TagComponent);
		Component_RegisterType(TransformComponent);
		Component_RegisterType(MeshComponent);
		Component_RegisterType(ScriptComponent);
		Component_RegisterType(CameraComponent);
		Component_RegisterType(SpriteRendererComponent);
	}

	void ScriptEngineRegistry::RegisterAll()
	{
		InitComponentTypes();

		mono_add_internal_call("Wolf.Noise::PerlinNoise_Native", Script::Wolf_Noise_PerlinNoise);

		mono_add_internal_call("Wolf.Entity::GetTransform_Native", Script::Wolf_Entity_GetTransform);
		mono_add_internal_call("Wolf.Entity::SetTransform_Native", Script::Wolf_Entity_SetTransform);
		mono_add_internal_call("Wolf.Entity::CreateComponent_Native", Script::Wolf_Entity_CreateComponent);
		mono_add_internal_call("Wolf.Entity::HasComponent_Native", Script::Wolf_Entity_HasComponent);

		mono_add_internal_call("Wolf.MeshComponent::GetMesh_Native", Script::Wolf_MeshComponent_GetMesh);
		mono_add_internal_call("Wolf.MeshComponent::SetMesh_Native", Script::Wolf_MeshComponent_SetMesh);

		mono_add_internal_call("Wolf.Input::IsKeyPressed_Native", Script::Wolf_Input_IsKeyPressed);

		mono_add_internal_call("Wolf.Texture2D::Constructor_Native", Script::Wolf_Texture2D_Constructor);
		mono_add_internal_call("Wolf.Texture2D::Destructor_Native", Script::Wolf_Texture2D_Destructor);
		mono_add_internal_call("Wolf.Texture2D::SetData_Native", Script::Wolf_Texture2D_SetData);

		mono_add_internal_call("Wolf.Material::Destructor_Native", Script::Wolf_Material_Destructor);
		mono_add_internal_call("Wolf.Material::SetFloat_Native", Script::Wolf_Material_SetFloat);
		mono_add_internal_call("Wolf.Material::SetTexture_Native", Script::Wolf_Material_SetTexture);

		mono_add_internal_call("Wolf.MaterialInstance::Destructor_Native", Script::Wolf_MaterialInstance_Destructor);
		mono_add_internal_call("Wolf.MaterialInstance::SetFloat_Native", Script::Wolf_MaterialInstance_SetFloat);
		mono_add_internal_call("Wolf.MaterialInstance::SetVector3_Native", Script::Wolf_MaterialInstance_SetVector3);
		mono_add_internal_call("Wolf.MaterialInstance::SetVector4_Native", Script::Wolf_MaterialInstance_SetVector4);
		mono_add_internal_call("Wolf.MaterialInstance::SetTexture_Native", Script::Wolf_MaterialInstance_SetTexture);

		mono_add_internal_call("Wolf.Mesh::Constructor_Native", Script::Wolf_Mesh_Constructor);
		mono_add_internal_call("Wolf.Mesh::Destructor_Native", Script::Wolf_Mesh_Destructor);
		mono_add_internal_call("Wolf.Mesh::GetMaterial_Native", Script::Wolf_Mesh_GetMaterial);
		mono_add_internal_call("Wolf.Mesh::GetMaterialByIndex_Native", Script::Wolf_Mesh_GetMaterialByIndex);
		mono_add_internal_call("Wolf.Mesh::GetMaterialCount_Native", Script::Wolf_Mesh_GetMaterialCount);

		mono_add_internal_call("Wolf.MeshFactory::CreatePlane_Native", Script::Wolf_MeshFactory_CreatePlane);

		//static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }

		//static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		//static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		//static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		//static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	}
}