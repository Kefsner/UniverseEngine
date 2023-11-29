#include "uepch.h"
#include "Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Universe {

	Application::Application()
	{
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            std::cout << "Failed to initialize GLFW" << std::endl;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            std::cout << "Failed to create a window" << std::endl;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
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