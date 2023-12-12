// Entry point of the application. It has the main function and start by creating an application
// With the function implemented inside the Sandbox
// It is the connection between the Engine and Sandbox.
#pragma once
#include "Universe.h"

int main()
{
	Universe::Log::Init();

	UE_CORE_INFO("Creating Universe!");
	auto universe = Universe::CreateApplication();

	UE_CORE_INFO("Running Universe!");
	universe->Run();

	UE_CORE_INFO("Closing Universe!");
	delete universe;

	return 0;
}