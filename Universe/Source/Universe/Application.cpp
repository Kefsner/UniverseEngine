#include "Application.h"
#include <iostream>

namespace Universe {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Running Application" << std::endl;
		while (true);
	}
}