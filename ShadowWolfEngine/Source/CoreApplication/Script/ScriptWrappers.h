#pragma once

#include "CoreApplication/Script/ScriptEngine.h"
#include "CoreApplication/Core/InputCore/KeyCodes.h"

#include <glm/glm.hpp>

extern "C" {
	typedef struct _MonoString MonoString;
	typedef struct _MonoArray MonoArray;
}

namespace Wolf
{
	namespace Script
	{
		// Math
		float Wolf_Noise_PerlinNoise(float x, float y);

		// Input
		bool Wolf_Input_IsKeyPressed(KeyCode key);

		// Entity
		void Wolf_Entity_GetTransform(uint64_t entityID, glm::mat4* outTransform);
		void Wolf_Entity_SetTransform(uint64_t entityID, glm::mat4* inTransform);
		void Wolf_Entity_CreateComponent(uint64_t entityID, void* type);
		bool Wolf_Entity_HasComponent(uint64_t entityID, void* type);

		void* Wolf_MeshComponent_GetMesh(uint64_t entityID);
		void Wolf_MeshComponent_SetMesh(uint64_t entityID, Ref<Mesh>* inMesh);

		// Renderer
		// Texture2D
		void* Wolf_Texture2D_Constructor(uint32_t width, uint32_t height);
		void Wolf_Texture2D_Destructor(Ref<Texture2D>* _this);
		void Wolf_Texture2D_SetData(Ref<Texture2D>* _this, MonoArray* inData, int32_t count);

		// Material
		void Wolf_Material_Destructor(Ref<Material>* _this);
		void Wolf_Material_SetFloat(Ref<Material>* _this, MonoString* uniform, float value);
		void Wolf_Material_SetTexture(Ref<Material>* _this, MonoString* uniform, Ref<Texture2D>* texture);

		void Wolf_MaterialInstance_Destructor(Ref<MaterialInstance>* _this);
		void Wolf_MaterialInstance_SetFloat(Ref<MaterialInstance>* _this, MonoString* uniform, float value);
		void Wolf_MaterialInstance_SetVector3(Ref<MaterialInstance>* _this, MonoString* uniform, glm::vec3* value);
		void Wolf_MaterialInstance_SetVector4(Ref<MaterialInstance>* _this, MonoString* uniform, glm::vec4* value);
		void Wolf_MaterialInstance_SetTexture(Ref<MaterialInstance>* _this, MonoString* uniform, Ref<Texture2D>* texture);

		// Mesh
		Ref<Mesh>* Wolf_Mesh_Constructor(MonoString* filepath);
		void Wolf_Mesh_Destructor(Ref<Mesh>* _this);
		Ref<Material>* Wolf_Mesh_GetMaterial(Ref<Mesh>* inMesh);
		Ref<MaterialInstance>* Wolf_Mesh_GetMaterialByIndex(Ref<Mesh>* inMesh, int index);
		int Wolf_Mesh_GetMaterialCount(Ref<Mesh>* inMesh);

		void* Wolf_MeshFactory_CreatePlane(float width, float height);
	}
}