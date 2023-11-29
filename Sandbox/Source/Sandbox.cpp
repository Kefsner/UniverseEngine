#include"uepch.h"
#include "Universe.h"

class Sandbox : public Universe::Application
{
public:
	Sandbox()
	{
		std::cout << "Constructed Sandbox!" << std::endl;
	}

	~Sandbox()
	{
	}
};

Universe::Application* Universe::CreateApplication()
{
	return new Sandbox();
}