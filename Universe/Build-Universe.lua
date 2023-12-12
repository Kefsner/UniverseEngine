project "Universe"
    kind "SharedLib"
	language "C++"
    cppdialect "C++latest"

    files {
        "Source/**.cpp",
        "Source/**.h",
        "Vendor/glm/glm/**.hpp",
        "Vendor/glm/glm/**.inl"
    }

    IncludeDir = {}
    IncludeDir["GLFW"] = "Vendor/GLFW/include"
    IncludeDir["glad"] = "Vendor/glad/include"
    IncludeDir["ImGui"] = "Vendor/imgui"
    IncludeDir["spdlog"] = "Vendor/spdlog/include"
    IncludeDir["glm"] = "Vendor/glm"

    includedirs {
        "Source",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}" ,
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
        "glad",
        "ImGui"
    }

    targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("../bin/int/" .. OutputDir .. "/%{prj.name}")

    pchheader "UEpch.h"
    pchsource "Source/UEpch.cpp"

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