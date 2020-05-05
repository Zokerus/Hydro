workspace "Hydro"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root directory
IncludeDir = {}
IncludeDir["GLFW"] = "Hydro/vendor/GLFW/include"

include "Hydro/vendor/GLFW"

-- startproject "Sandbox"
	
project "Hydro"
	location "Hydro"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "pch.h"
	pchsource "Hydro/src/pch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	
	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"HD_PLATFORM_WINDOWS",
			"HD_BUILD_DLL"
		}
		
	filter "configurations:Debug"
		defines "HD_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HD_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "HD_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs 
	{
		"Hydro/vendor/spdlog/include",
		"Hydro/src"
	}
	
	links
	{
		"Hydro"
	}
	
	prebuildcommands
		{
			("{COPY} ../bin/" .. outputdir .. "/Hydro/Hydro.dll %{cfg.targetdir}")
		}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"HD_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "HD_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HD_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "HD_DIST"
		optimize "On"