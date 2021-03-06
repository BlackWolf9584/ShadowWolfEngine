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
IncludeDir["entt"] = "ShadowWolfEngine/Dependencies/entt"
IncludeDir["FastNoise"] = "ShadowWolfEngine/Dependencies/FastNoise"
IncludeDir["mono"] = "ShadowWolfEngine/Dependencies/mono/include"

LibraryDir = {}
LibraryDir["mono"] = "Dependencies/mono/lib/debug/mono-2.0-sgen.lib"

group "Dependencies"
include "ShadowWolfEngine/Dependencies/GLFW"
include "ShadowWolfEngine/Dependencies/Glad"
include "ShadowWolfEngine/Dependencies/ImGui"

group "Core"
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
		"%{prj.name}/Source/**.cpp",
		
		"%{prj.name}/Dependencies/FastNoise/**.cpp",

		"%{prj.name}/Dependencies/yaml-cpp/src/**.cpp",
		"%{prj.name}/Dependencies/yaml-cpp/src/**.h",
		"%{prj.name}/Dependencies/yaml-cpp/include/**.h"

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
		"%{IncludeDir.entt}",
		"%{IncludeDir.FastNoise}",
		"%{IncludeDir.mono}",
		"%{prj.name}/Dependencies/SPDLOG/include",
		"%{prj.name}/Dependencies/Assimp/include",
		"%{prj.name}/Dependencies/stb/include",
		"%{prj.name}/Dependencies/yaml-cpp/include"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"%{LibraryDir.mono}",
		"ShadowWolf-ScriptCore"
	}

	filter "files:ShadowWolfEngine/Dependencies/FastNoise/**.cpp or files:ShadowWolfEngine/Dependencies/yaml-cpp/src/**.cpp"
	flags {"NoPCH"}

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

project "ShadowWolf-ScriptCore"
	location "ShadowWolf-ScriptCore"
	kind "SharedLib"
	language "C#"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.cs", 
	}

group "Tools"
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
		"%{IncludeDir.entt}",
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
			"ShadowWolfEngine/Dependencies/Assimp/win64/Debug/assimp-vc141-mtd.lib"
		}

		postbuildcommands 
		{
			'{COPY} "../ShadowWolfEngine/Dependencies/Assimp/win64/Debug/assimp-vc141-mtd.dll" "%{cfg.targetdir}"',
			'{COPY} "../ShadowWolfEngine/Dependencies/mono/bin/Debug/mono-2.0-sgen.dll" "%{cfg.targetdir}"'
		}
				
	filter "configurations:Release"
		defines "SW_RELEASE"
		optimize "on"

		links
		{
			"ShadowWolfEngine/Dependencies/Assimp/win64/Release/assimp-vc141-mt.lib"
		}

		postbuildcommands 
		{
			'{COPY} "../ShadowWolfEngine/Dependencies/Assimp/win64/Release/assimp-vc141-mtd.dll" "%{cfg.targetdir}"',
			'{COPY} "../ShadowWolfEngine/Dependencies/mono/bin/Debug/mono-2.0-sgen.dll" "%{cfg.targetdir}"'
		}

	filter "configurations:Dist"
		defines "SW_DIST"
		optimize "on"

		links
		{
			"ShadowWolfEngine/Dependencies/Assimp/win64/Release/assimp-vc141-mt.lib"
		}

		postbuildcommands 
		{
			'{COPY} "../ShadowWolfEngine/Dependencies/Assimp/win64/Release/assimp-vc141-mtd.dll" "%{cfg.targetdir}"',
			'{COPY} "../ShadowWolfEngine/Dependencies/mono/bin/Debug/mono-2.0-sgen.dll" "%{cfg.targetdir}"'
		}