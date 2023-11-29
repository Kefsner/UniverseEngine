// Entry point of the application. It has the main function and start by creating an application
// With the function implemented inside the Sandbox
// It is the connection between the Engine and Sandbox.
#pragma once
#include "Universe.h"

int main()
{
	auto app = Universe::CreateApplication();

	app->Run();

	delete app;

	return 0;
}