#pragma once
#include "Script/ScriptEngine.h"
#include "Core/InputCore/KeyCodes.h"

#include <mono/metadata/object.h>
#include <glm/glm.hpp>

namespace SW
{
	namespace Script
	{
		// Math
		float SW_Noise_PerlinNoise(float x, float y);

		// Input
		bool SW_Input_IsKeyPressed(KeyCode key);

		// Entity
		void SW_Entity_GetTransform(uint64_t entityID, glm::mat4* outTransform);
		void SW_Entity_SetTransform(uint64_t entityID, glm::mat4* inTransform);
		void SW_Entity_CreateComponent(uint64_t entityID, void* type);
		bool SW_Entity_HasComponent(uint64_t entityID, void* type);

		void* SW_MeshComponent_GetMesh(uint64_t entityID);
		void SW_MeshComponent_SetMesh(uint64_t entityID, Ref<Mesh>* inMesh);

		// Renderer
		// Texture2D
		void* SW_Texture2D_Constructor(uint32_t width, uint32_t height);
		void SW_Texture2D_Destructor(Ref<Texture2D>* _this);
		void SW_Texture2D_SetData(Ref<Texture2D>* _this, MonoArray* inData, int32_t count);

		// Material
		void SW_Material_Destructor(Ref<Material>* _this);
		void SW_Material_SetFloat(Ref<Material>* _this, MonoString* uniform, float value);
		void SW_Material_SetTexture(Ref<Material>* _this, MonoString* uniform, Ref<Texture2D>* texture);

		void SW_MaterialInstance_Destructor(Ref<MaterialInstance>* _this);
		void SW_MaterialInstance_SetFloat(Ref<MaterialInstance>* _this, MonoString* uniform, float value);
		void SW_MaterialInstance_SetVector3(Ref<MaterialInstance>* _this, MonoString* uniform, glm::vec3* value);
		void SW_MaterialInstance_SetVector4(Ref<MaterialInstance>* _this, MonoString* uniform, glm::vec4* value);
		void SW_MaterialInstance_SetTexture(Ref<MaterialInstance>* _this, MonoString* uniform, Ref<Texture2D>* texture);

		// Mesh
		Ref<Mesh>* SW_Mesh_Constructor(MonoString* filepath);
		void SW_Mesh_Destructor(Ref<Mesh>* _this);
		Ref<Material>* SW_Mesh_GetMaterial(Ref<Mesh>* inMesh);
		Ref<MaterialInstance>* SW_Mesh_GetMaterialByIndex(Ref<Mesh>* inMesh, int index);
		int SW_Mesh_GetMaterialCount(Ref<Mesh>* inMesh);

		void* SW_MeshFactory_CreatePlane(float width, float height);


	}
}