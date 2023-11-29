#include "UEpch.h"
#include "WindowsWindow.h"

namespace Universe {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		if (!s_GLFWInitialized)
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW" << std::endl;
			}

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			std::cout << "Failed to create a window" << std::endl;
		}

		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		//// Set GLFW Callbacks
		//glfwSetWindowSizeCallback(m_Window);
	}

	WindowsWindow::~WindowsWindow()
	{
		// This is not terminating glfw because we could have more than one window
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);

		/* Poll for and process events */
		glfwPollEvents();
	}
}