#pragma once

#include "Engine.h"
#include "CoreApplication/ImGui/ImGuiLayer.h"
#include "CoreApplication/Editor/EditorComponents/EditorCamera.h"
#include "imgui/imgui_internal.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <string>
#include "CoreApplication/Core/AssetBrowserCore/AssetManager.h"
#include "CoreApplication/Core/AssetBrowserCore/DirectoryInformation.h"
#include "CoreApplication/Editor/Panels/SceneHierarchyPanel.h"

namespace Wolf {

	class EditorLayer : public Layer
	{
	public:
		enum class PropertyFlag
		{
			None = 0, ColorProperty = 1, DragProperty = 2, SliderProperty = 4
		};
	public:
		EditorLayer();
		virtual ~EditorLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(Timestep ts) override;

		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		// ImGui UI helpers
		bool Property(const std::string& name, bool& value);
		bool Property(const std::string& name, float& value, float min = -1.0f, float max = 1.0f, PropertyFlag flags = PropertyFlag::None);
		bool Property(const std::string& name, glm::vec2& value, PropertyFlag flags);
		bool Property(const std::string& name, glm::vec2& value, float min = -1.0f, float max = 1.0f, PropertyFlag flags = PropertyFlag::None);
		bool Property(const std::string& name, glm::vec3& value, PropertyFlag flags);
		bool Property(const std::string& name, glm::vec3& value, float min = -1.0f, float max = 1.0f, PropertyFlag flags = PropertyFlag::None);
		bool Property(const std::string& name, glm::vec4& value, PropertyFlag flags);
		bool Property(const std::string& name, glm::vec4& value, float min = -1.0f, float max = 1.0f, PropertyFlag flags = PropertyFlag::None);

		void ShowBoundingBoxes(bool show, bool onTop = false);
		void SelectEntity(Entity entity);
	private:
		std::pair<float, float> GetMouseViewportSpace();
		std::pair<glm::vec3, glm::vec3> CastRay(float mx, float my);

		struct SelectedSubmesh
		{
			Wolf::Entity Entity;
			Submesh* Mesh = nullptr;
			float Distance = 0.0f;
		};

		void OnSelected(const SelectedSubmesh& selectionContext);
		void OnEntityDeleted(Entity e);
		Ray CastMouseRay();

		void OnScenePlay();
		void OnSceneStop();

		void UpdateWindowTitle(const std::string& sceneName);
	private:
		Scope<SceneHierarchyPanel> m_SceneHierarchyPanel;

		Ref<Scene> m_RuntimeScene, m_EditorScene;
		bool m_ReloadScriptOnPlay = false;

		EditorCamera m_EditorCamera;

		Ref<Shader> m_BrushShader;
		Ref<Material> m_SphereBaseMaterial;

		Ref<Material> m_MeshMaterial;
		std::vector<Ref<MaterialInstance>> m_MetalSphereMaterialInstances;
		std::vector<Ref<MaterialInstance>> m_DielectricSphereMaterialInstances;

		std::string m_CurrentDirPath;
		std::string m_BaseDirPath;
		std::string m_prevDirPath;

		int m_basePathLen;

		std::vector<DirectoryInformation> m_CurrentDir;
		std::vector<DirectoryInformation> m_BaseProjectDir;

		struct AlbedoInput
		{
			glm::vec3 Color = { 0.972f, 0.96f, 0.915f }; // Silver, from https://docs.unrealengine.com/en-us/Engine/Rendering/Materials/PhysicallyBased
			Ref<Texture2D> TextureMap;
			bool SRGB = true;
			bool UseTexture = false;
		};
		AlbedoInput m_AlbedoInput;

		struct NormalInput
		{
			Ref<Texture2D> TextureMap;
			bool UseTexture = false;
		};
		NormalInput m_NormalInput;

		struct MetalnessInput
		{
			float Value = 1.0f;
			Ref<Texture2D> TextureMap;
			bool UseTexture = false;
		};
		MetalnessInput m_MetalnessInput;

		struct RoughnessInput
		{
			float Value = 0.2f;
			Ref<Texture2D> TextureMap;
			bool UseTexture = false;
		};
		RoughnessInput m_RoughnessInput;

		// PBR params
		bool m_RadiancePrefilter = false;

		float m_EnvMapRotation = 0.0f;

		enum class SceneType : uint32_t
		{
			Spheres = 0, Model = 1
		};
		SceneType m_SceneType;

		// Editor resources
		Ref<Texture2D> m_CheckerboardTex;
		Ref<Texture2D> m_PlayButtonTex;
		Ref<Texture2D> m_folderTex;
		Ref<Texture2D> m_favoritesTex;
		Ref<Texture2D> m_FileTex;
		Ref<Texture2D> m_goBackTex;


		glm::vec2 m_ViewportBounds[2];
		int m_GizmoType = -1; // -1 = no gizmo
		float m_SnapValue = 0.5f;
		bool m_AllowViewportCameraEvents = false;
		bool m_DrawOnTopBoundingBoxes = false;

		bool m_UIShowBoundingBoxes = false;
		bool m_UIShowBoundingBoxesOnTop = false;

		bool m_ViewportPanelMouseOver = false;
		bool m_ViewportPanelFocused = false;

		enum class SceneState
		{
			Edit = 0, Play = 1, Pause = 2
		};
		SceneState m_SceneState = SceneState::Edit;

		enum class SelectionMode
		{
			None = 0, Entity = 1, SubMesh = 2
		};

		SelectionMode m_SelectionMode = SelectionMode::Entity;
		std::vector<SelectedSubmesh> m_SelectionContext;
		glm::mat4* m_RelativeTransform = nullptr;
		glm::mat4* m_CurrentlySelectedTransform = nullptr;
	};

}
