#include "SWpch.h"
#include "CoreApplication/Renderer/Shader.h"
#include "CoreApplication/Renderer/Renderer.h"
#include "CoreApplication/Platform/OpenGL/OpenGLShader.h"

namespace SW
{
	std::vector<Ref<Shader>> Shader::s_AllShaders;

	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		Ref<Shader> result = nullptr;

		switch (RendererAPI::Current())
		{
		case RendererAPIType::None: return nullptr;
		case RendererAPIType::OpenGL: result = Ref<OpenGLShader>::Create(filepath);
		}
		s_AllShaders.push_back(result);
		return result;
	}

	Ref<Shader> Shader::CreateFromString(const std::string& source)
	{
		Ref<Shader> result = nullptr;

		switch (RendererAPI::Current())
		{
		case RendererAPIType::None: return nullptr;
		case RendererAPIType::OpenGL: result = OpenGLShader::CreateFromString(source);
		}
		s_AllShaders.push_back(result);
		return result;
	}

	ShaderLibrary::ShaderLibrary()
	{
	}

	ShaderLibrary::~ShaderLibrary()
	{
	}

	void ShaderLibrary::Add(const SW::Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		SW_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end());
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Load(const std::string& path)
	{
		auto shader = Ref<Shader>(Shader::Create(path));
		auto& name = shader->GetName();
		SW_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end());
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Load(const std::string& name, const std::string& path)
	{
		SW_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end());
		m_Shaders[name] = Ref<Shader>(Shader::Create(path));
	}

	const Ref<Shader>& ShaderLibrary::Get(const std::string& name) const
	{
		SW_CORE_ASSERT(m_Shaders.find(name) != m_Shaders.end());
		return m_Shaders.at(name);
	}

}