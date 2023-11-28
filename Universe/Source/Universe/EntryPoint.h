#pragma once
#include "Universe.h"

int main()
{
	auto app = Universe::CreateApplication();

	app->Run();

	delete app;

	return 0;
}