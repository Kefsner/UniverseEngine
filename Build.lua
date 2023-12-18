workspace "Universe"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "Sandbox"

	-- Build options for MSVC
	filter "system:windows"
		buildoptions { "/std:c++latest", "/Zc:__cplusplus" }
		defines 
		{
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",  -- Silence spdlog warning about stdext
			"_CRT_SECURE_NO_WARNINGS" -- Silence imgui warning about sscanf, strcpy and strcat
		}

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Universe/Build-Universe.lua"

include "Universe/Vendor/GLFW/Build-GLFW.lua"
include "Universe/Vendor/glad/Build-glad.lua"
include "Universe/Vendor/imgui/Build-imgui.lua"

include "Sandbox/Build-Sandbox.lua"