// Main application header file.
#pragma once
#include "Universe/Events/ApplicationEvent.h"
#include "Universe/Events/Event.h"

#include "Universe/Core/LayerStack.h"
#include "Universe/Core/Window.h"

#include "Universe/ImGui/ImGuiLayer.h"

#include "Universe/Renderer/Shader.h"
#include "Universe/Renderer/Buffer.h"

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

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	};

	// By keeping this function outside of the application class,
	// the client can define it's own application class and create
	Application* CreateApplication();
}