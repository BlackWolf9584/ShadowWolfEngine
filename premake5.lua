workspace "ShadowWolf"
	architecture "x64"
	targetdir "build"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Playground"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ShadowWolfEngine/Dependencies/GLFW/include"
IncludeDir["Glad"] = "ShadowWolfEngine/Dependencies/Glad/include"
IncludeDir["ImGui"] = "ShadowWolfEngine/Dependencies/ImGui"
IncludeDir["glm"] = "ShadowWolfEngine/Dependencies/glm"

include "ShadowWolfEngine/Dependencies/GLFW"
include "ShadowWolfEngine/Dependencies/Glad"
include "ShadowWolfEngine/Dependencies/ImGui"

project "ShadowWolfEngine"
	location "ShadowWolfEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "SWpch.h"
	pchsource "ShadowWolfEngine/Source/SWpch.cpp"

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 
	}

	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/Source/CoreApplication",
		"%{prj.name}/Source/CoreApplication/Core",
		"%{prj.name}/Source/CoreApplication/Core/Debug",
		"%{prj.name}/Source/CoreApplication/Core/Events",
		"%{prj.name}/Source/CoreApplication/Core/InputCore",
		"%{prj.name}/Source/CoreApplication/Core/Utilities",
		"%{prj.name}/Source/CoreApplication/ImGui",
		"%{prj.name}/Source/CoreApplication/Platform",
		"%{prj.name}/Source/CoreApplication/Platform/OpenGL",
		"%{prj.name}/Source/CoreApplication/Platform/Windows",
		"%{prj.name}/Source/CoreApplication/Platform/DirectX",
		"%{prj.name}/Source/CoreApplication/Platform/Vulkan",
		"%{prj.name}/Source/CoreApplication/Renderer",
		"%{prj.name}/Dependencies",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{prj.name}/Dependencies/Assimp/include",
		"%{prj.name}/Dependencies/stb/include"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SW_PLATFORM_WINDOWS",
			"SW_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "SW_DEBUG"
		symbols "On"
				
	filter "configurations:Release"
		defines "SW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SW_DIST"
		optimize "On"

project "Playground"
	location "Playground"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	links
	{
		"ShadowWolfEngine"
	}

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 	
	}

	includedirs
	{
		"%{prj.name}/src",
		"ShadowWolfEngine/Source",
		"ShadowWolfEngine/Dependencies",
		"%{IncludeDir.glm}"
	}

	postbuildcommands
	{
		'{COPY} "../Playground/Assets" "%{cfg.targetdir}/Assets"'
	}

	filter "system:windows"
		systemversion "latest"
				
		defines 
		{ 
			"SW_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "SW_DEBUG"
		symbols "on"

		links
		{
			"ShadowWolfEngine/Dependencies/Assimp/bin/Debug/assimp-vc141-mtd.lib"
		}

		postbuildcommands 
		{
			'{COPY} "../ShadowWolfEngine/Dependencies/Assimp/bin/Debug/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
		}
				
	filter "configurations:Release"
		defines "SW_RELEASE"
		optimize "on"

		links
		{
			"ShadowWolfEngine/Dependencies/Assimp/bin/Release/assimp-vc141-mt.lib"
		}

		postbuildcommands 
		{
			'{COPY} "../ShadowWolfEngine/Dependencies/Assimp/bin/Release/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
		}

	filter "configurations:Dist"
		defines "SW_DIST"
		optimize "on"

		links
		{
			"ShadowWolfEngine/Dependencies/Assimp/bin/Release/assimp-vc141-mt.lib"
		}

		postbuildcommands 
		{
			'{COPY} "../ShadowWolfEngine/Dependencies/Assimp/bin/Release/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
		}