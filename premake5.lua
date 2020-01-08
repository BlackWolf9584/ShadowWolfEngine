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
		"%{prj.name}/Source/**.h", 
		"%{prj.name}/Source/**.c", 
		"%{prj.name}/Source/**.hpp", 
		"%{prj.name}/Source/**.cpp" 
	}

	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/Source/CoreApplication",
		"%{prj.name}/Source/CoreApplication/Core",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{prj.name}/Dependencies/SPDLOG/include",
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
		"%{prj.name}/Source/**.h", 
		"%{prj.name}/Source/**.c", 
		"%{prj.name}/Source/**.hpp", 
		"%{prj.name}/Source/**.cpp" 	
	}

	includedirs
	{
		"%{prj.name}/Source",
		"ShadowWolfEngine/Source",
		"ShadowWolfEngine/Dependencies",
		"ShadowWolfEngine/Dependencies/SPDLOG/include",
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