// Main application header file.
#pragma once
#include "Core.h"
#include "Window.h"

namespace Universe {

	class UE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
		const char* e = "Event";

		void OnEvent(const char* e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	};

	Application* CreateApplication();
}