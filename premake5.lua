workspace "Slurp"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Slurp"
	location "Slurp"
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
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/SFML/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"SLURP_PLATFORM_WINDOWS",
			"SLURP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		libdirs
		{
			"%{prj.name}/vendor/SFML/lib"
		}

	filter "configurations:Debug"
		defines "SLURP_DEBUG"
		symbols "On"

		links
        {
            "sfml-audio-d.lib",
            "sfml-graphics-d.lib",
            "sfml-network-d.lib",
            "sfml-system-d.lib",
            "sfml-window-d.lib"
        }

	filter "configurations:Release"
		defines "SLURP_RELEASE"
		optimize "On"
		
		links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }

	filter "configurations:Dist"
		defines "SLURP_DIST"
		optimize "On"

		links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }

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
		"Slurp/vendor/spdlog/include",
		"Slurp/vendor/SFML/include",
		"Slurp/src"
	}

	links
	{
		"Slurp"
	}

	postbuildcommands
	{
		("{COPY} ../Slurp/vendor/SFML/bin/ ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"SLURP_PLATFORM_WINDOWS"
		}

		libdirs
        {
            "Slurp/vendor/SFML/lib"
        }

	filter "configurations:Debug"
		defines "SLURP_DEBUG"
		symbols "On"

		links
        {
            "sfml-audio-d.lib",
            "sfml-graphics-d.lib",
            "sfml-network-d.lib",
            "sfml-system-d.lib",
            "sfml-window-d.lib"
        }

	filter "configurations:Release"
		defines "SLURP_RELEASE"
		optimize "On"

		links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }

	filter "configurations:Dist"
		defines "SLURP_DIST"
		optimize "On"

		 links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }