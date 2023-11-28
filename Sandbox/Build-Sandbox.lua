project "Sandbox"
	kind "ConsoleApp"
	language "C++"
    cppdialect "C++latest"

	files { "Source/**.cpp", "Source/**.h" }

	includedirs {"Source", "../Universe/Source"}

	links
	{
		"Universe"
	}

	targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("../bin/int/" .. OutputDir .. "/%{prj.name}")

    filter "system:windows"
		systemversion "latest"
        defines "UE_PLATFORM_WINDOWS"

	filter "configurations:Debug"
		defines "UE_DEBUG"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "UE_RELEASE"
        runtime "Release"
		optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines "UE_DIST"
        runtime "Release"
        optimize "On"
        symbols "Off"