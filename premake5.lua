workspace "Sqwack Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sqwack_Engine"
	location "Sqwack_Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime("on")

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Sqwack_Engine/Sqwack/src/pch.cpp"

	links
	{
		"D3d12",
		"DXGI"
	}
	
	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/Sqwack/src",
		"%{prj.name}"
		
	}

	filter "system:windows"
		
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQWACK_PLATFORM_WINDOWS",
			"SQWACK_BUILD_DLL",
			"_WINDLL"
		}


	filter "configurations:Debug"
		defines "SQWACK_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "SQWACK_Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SQWACK_Dist"
		optimize "on"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"

	}

	includedirs
	{
		"Sqwack_Engine/Sqwack/src",
		"%{prj.name}"
	}

	links
	{
		"Sqwack_Engine"
	}

		filter "system:windows"

		staticruntime "on"1
		systemversion "latest"

		defines
		{
			"SQWACK_PLATFORM_WINDOWS",
			"SQWACK_BUILD_DLL",
			"_WINDLL"
		}


	filter "configurations:Debug"
		defines "SQWACK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SQWACK_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SQWACK_Dist"
		optimize "On"
