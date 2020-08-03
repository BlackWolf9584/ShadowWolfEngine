#include "SWpch.h"
#include "ScriptWrappers.h"
#include "Core/Math/Noise.h"
#include "Scene/Scene.h"
#include "Scene/Entity.h"
#include "Scene/Components.h"
#include "Core/InputCore/Input.h"
#include <glm/gtc/type_ptr.hpp>
#include <mono/jit/jit.h>

namespace SW 
{
	extern std::unordered_map<MonoType*, std::function<bool(Entity&)>> s_HasComponentFuncs;
	extern std::unordered_map<MonoType*, std::function<void(Entity&)>> s_CreateComponentFuncs;
}

namespace SW
{
	namespace Script
	{
		enum class ComponentID
		{
			None = 0,
			Transform = 1,
			Mesh = 2,
			Script = 3,
			SpriteRenderer = 4
		};



		////////////////////////////////////////////////////////////////
		// Math ////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////

		float SW_Noise_PerlinNoise(float x, float y)
		{
			return Noise::PerlinNoise(x, y);
		}

		////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////
		// Input ///////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////

		bool SW_Input_IsKeyPressed(KeyCode key)
		{
			return Input::IsKeyPressed(key);
		}

		////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////
		// Entity //////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////

		void SW_Entity_GetTransform(uint64_t entityID, glm::mat4* outTransform)
		{
			Ref<Scene> scene = ScriptEngine::GetCurrentSceneContext();
			SW_CORE_ASSERT(scene, "No active scene!");
			const auto& entityMap = scene->GetEntityMap();
			SW_CORE_ASSERT(entityMap.find(entityID) != entityMap.end(), "Invalid entity ID or entity doesn't exist in scene!");

			Entity entity = entityMap.at(entityID);
			auto& transformComponent = entity.GetComponent<TransformComponent>();
			memcpy(outTransform, glm::value_ptr(transformComponent.Transform), sizeof(glm::mat4));
		}

		void SW_Entity_SetTransform(uint64_t entityID, glm::mat4* inTransform)
		{
			Ref<Scene> scene = ScriptEngine::GetCurrentSceneContext();
			SW_CORE_ASSERT(scene, "No active scene!");
			const auto& entityMap = scene->GetEntityMap();
			SW_CORE_ASSERT(entityMap.find(entityID) != entityMap.end(), "Invalid entity ID or entity doesn't exist in scene!");

			Entity entity = entityMap.at(entityID);
			auto& transformComponent = entity.GetComponent<TransformComponent>();
			memcpy(glm::value_ptr(transformComponent.Transform), inTransform, sizeof(glm::mat4));
		}

		void SW_Entity_CreateComponent(uint64_t entityID, void* type)
		{
			Ref<Scene> scene = ScriptEngine::GetCurrentSceneContext();
			SW_CORE_ASSERT(scene, "No active scene!");
			const auto& entityMap = scene->GetEntityMap();
			SW_CORE_ASSERT(entityMap.find(entityID) != entityMap.end(), "Invalid entity ID or entity doesn't exist in scene!");

			Entity entity = entityMap.at(entityID);
			MonoType* monoType = mono_reflection_type_get_type((MonoReflectionType*)type);
			s_CreateComponentFuncs[monoType](entity);
		}

		bool SW_Entity_HasComponent(uint64_t entityID, void* type)
		{
			Ref<Scene> scene = ScriptEngine::GetCurrentSceneContext();
			SW_CORE_ASSERT(scene, "No active scene!");
			const auto& entityMap = scene->GetEntityMap();
			SW_CORE_ASSERT(entityMap.find(entityID) != entityMap.end(), "Invalid entity ID or entity doesn't exist in scene!");

			Entity entity = entityMap.at(entityID);
			MonoType* monoType = mono_reflection_type_get_type((MonoReflectionType*)type);
			bool result = s_HasComponentFuncs[monoType](entity);
			return result;
		}

		void* SW_MeshComponent_GetMesh(uint64_t entityID)
		{
			Ref<Scene> scene = ScriptEngine::GetCurrentSceneContext();
			SW_CORE_ASSERT(scene, "No active scene!");
			const auto& entityMap = scene->GetEntityMap();
			SW_CORE_ASSERT(entityMap.find(entityID) != entityMap.end(), "Invalid entity ID or entity doesn't exist in scene!");

			Entity entity = entityMap.at(entityID);
			auto& meshComponent = entity.GetComponent<MeshComponent>();
			return new Ref<Mesh>(meshComponent.Mesh);
		}

		void SW_MeshComponent_SetMesh(uint64_t entityID, Ref<Mesh>* inMesh)
		{
			Ref<Scene> scene = ScriptEngine::GetCurrentSceneContext();
			SW_CORE_ASSERT(scene, "No active scene!");
			const auto& entityMap = scene->GetEntityMap();
			SW_CORE_ASSERT(entityMap.find(entityID) != entityMap.end(), "Invalid entity ID or entity doesn't exist in scene!");

			Entity entity = entityMap.at(entityID);
			auto& meshComponent = entity.GetComponent<MeshComponent>();
			meshComponent.Mesh = inMesh ? *inMesh : nullptr;
		}

		Ref<Mesh>* SW_Mesh_Constructor(MonoString* filepath)
		{
			return new Ref<Mesh>(new Mesh(mono_string_to_utf8(filepath)));
		}

		void SW_Mesh_Destructor(Ref<Mesh>* _this)
		{
			Ref<Mesh>* instance = (Ref<Mesh>*)_this;
			delete _this;
		}

		Ref<Material>* SW_Mesh_GetMaterial(Ref<Mesh>* inMesh)
		{
			Ref<Mesh>& mesh = *(Ref<Mesh>*)inMesh;
			return new Ref<Material>(mesh->GetMaterial());
		}

		Ref<MaterialInstance>* SW_Mesh_GetMaterialByIndex(Ref<Mesh>* inMesh, int index)
		{
			Ref<Mesh>& mesh = *(Ref<Mesh>*)inMesh;
			const auto& materials = mesh->GetMaterials();

			SW_CORE_ASSERT(index < materials.size());
			return new Ref<MaterialInstance>(materials[index]);
		}

		int SW_Mesh_GetMaterialCount(Ref<Mesh>* inMesh)
		{
			Ref<Mesh>& mesh = *(Ref<Mesh>*)inMesh;
			const auto& materials = mesh->GetMaterials();
			return materials.size();
		}

		void* SW_Texture2D_Constructor(uint32_t width, uint32_t height)
		{
			auto result = Texture2D::Create(TextureFormat::RGBA, width, height);
			return new Ref<Texture2D>(result);
		}

		void SW_Texture2D_Destructor(Ref<Texture2D>* _this)
		{
			delete _this;
		}

		void SW_Texture2D_SetData(Ref<Texture2D>* _this, MonoArray* inData, int32_t count)
		{
			Ref<Texture2D>& instance = *_this;

			uint32_t dataSize = count * sizeof(glm::vec4) / 4;

			instance->Lock();
			Buffer buffer = instance->GetWriteableBuffer();
			SW_CORE_ASSERT(dataSize <= buffer.Size);
			// Convert RGBA32F color to RGBA8
			uint8_t* pixels = (uint8_t*)buffer.Data;
			uint32_t index = 0;
			for (int i = 0; i < instance->GetWidth() * instance->GetHeight(); i++)
			{
				glm::vec4& value = mono_array_get(inData, glm::vec4, i);
				*pixels++ = (uint32_t)(value.x * 255.0f);
				*pixels++ = (uint32_t)(value.y * 255.0f);
				*pixels++ = (uint32_t)(value.z * 255.0f);
				*pixels++ = (uint32_t)(value.w * 255.0f);
			}

			instance->Unlock();
		}

		void SW_Material_Destructor(Ref<Material>* _this)
		{
			delete _this;
		}

		void SW_Material_SetFloat(Ref<Material>* _this, MonoString* uniform, float value)
		{
			Ref<Material>& instance = *(Ref<Material>*)_this;
			instance->Set(mono_string_to_utf8(uniform), value);
		}

		void SW_Material_SetTexture(Ref<Material>* _this, MonoString* uniform, Ref<Texture2D>* texture)
		{
			Ref<Material>& instance = *(Ref<Material>*)_this;
			instance->Set(mono_string_to_utf8(uniform), *texture);
		}

		void SW_MaterialInstance_Destructor(Ref<MaterialInstance>* _this)
		{
			delete _this;
		}

		void SW_MaterialInstance_SetFloat(Ref<MaterialInstance>* _this, MonoString* uniform, float value)
		{
			Ref<MaterialInstance>& instance = *(Ref<MaterialInstance>*)_this;
			instance->Set(mono_string_to_utf8(uniform), value);
		}

		void SW_MaterialInstance_SetVector3(Ref<MaterialInstance>* _this, MonoString* uniform, glm::vec3* value)
		{
			Ref<MaterialInstance>& instance = *(Ref<MaterialInstance>*)_this;
			instance->Set(mono_string_to_utf8(uniform), *value);
		}

		void SW_MaterialInstance_SetVector4(Ref<MaterialInstance>* _this, MonoString* uniform, glm::vec4* value)
		{
			Ref<MaterialInstance>& instance = *(Ref<MaterialInstance>*)_this;
			instance->Set(mono_string_to_utf8(uniform), *value);
		}

		void SW_MaterialInstance_SetTexture(Ref<MaterialInstance>* _this, MonoString* uniform, Ref<Texture2D>* texture)
		{
			Ref<MaterialInstance>& instance = *(Ref<MaterialInstance>*)_this;
			instance->Set(mono_string_to_utf8(uniform), *texture);
		}

		void* SW_MeshFactory_CreatePlane(float width, float height)
		{
			// TODO: Implement properly with MeshFactory class!
			return new Ref<Mesh>(new Mesh("assets/models/Plane1m.obj"));
		}

		////////////////////////////////////////////////////////////////

	}
}