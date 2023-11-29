workspace "Universe"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "Sandbox"

	-- Build options for MSVC
	filter "system:windows"
		buildoptions { "/std:c++latest", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Universe/Build-Universe.lua"

include "Universe/Vendor/GLFW/Build-GLFW.lua"
include "Universe/Vendor/glad/Build-glad.lua"

include "Sandbox/Build-Sandbox.lua"