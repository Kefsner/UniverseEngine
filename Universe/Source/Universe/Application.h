// Main application header file.
#pragma once
#include "Core.h"

namespace Universe {

	class UE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();
}