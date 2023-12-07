#include "UEpch.h"
#include "Application.h"
#include <functional>

namespace Universe {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1))
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

	void Application::OnEvent(const char* e)
	{
		std::cout << "Event" << std::endl;
	}
}