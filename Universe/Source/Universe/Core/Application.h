// Main application header file.
#pragma once
#include "Universe/Events/ApplicationEvent.h"
#include "Universe/Events/Event.h"

#include "Universe/Core/LayerStack.h"
#include "Universe/Core/Window.h"

#include "Universe/ImGui/ImGuiLayer.h"

#include "Universe/Renderer/Shader.h"

namespace Universe {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }

	private:
		static Application* s_Instance;

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	};

	// By keeping this function outside of the application class,
	// the client can define it's own application class and create
	Application* CreateApplication();
}