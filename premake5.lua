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
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Sqwack_Engine/Sqwack/src/pch.cpp"

	
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQWACK_PLATFORM_WINDOWS",
			"SQWACK_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{Copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		cppdialect "C++17"
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
		symbols "On"

	filter "configurations:Release"
		defines "SQWACK_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SQWACK_Dist"
		optimize "On"
