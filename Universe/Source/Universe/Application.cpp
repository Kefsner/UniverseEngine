#include "uepch.h"
#include "Application.h"

namespace Universe {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			m_Window->OnUpdate( );
		}
	}
}