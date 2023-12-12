// Main application header file.
#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Universe {

	class UE_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		inline Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		static Application* s_Instance;

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}