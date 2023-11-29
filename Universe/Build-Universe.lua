project "Universe"
    kind "SharedLib"
	language "C++"
    cppdialect "C++latest"

    files {"Source/**.cpp", "Source/**.h"}

    IncludeDir = {}
    IncludeDir["GLFW"] = "Vendor/GLFW/include"

    includedirs {"Source", "%{IncludeDir.GLFW}"}

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("../bin/int/" .. OutputDir .. "/%{prj.name}")

    pchheader "uepch.h"
    pchsource "Source/uepch.cpp"

	filter "system:windows"
        systemversion "latest"
		defines {"UE_PLATFORM_WINDOWS", "UE_BUILD_DLL"}
        postbuildcommands
		{
			"{MKDIR} ../bin/" .. OutputDir .. "/Sandbox",
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. OutputDir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "UE_DEBUG"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "UE_RELEASE"
        runtime "Release"
		optimize "On"

    filter "configurations:Dist"
        defines "UE_DIST"
        runtime "Release"
        optimize "On"
        symbols "Off"