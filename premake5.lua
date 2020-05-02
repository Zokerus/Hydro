workspace "Hydro"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Hydro"
	location "Hydro"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
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