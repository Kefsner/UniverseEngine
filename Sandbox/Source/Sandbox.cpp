#include"uepch.h"
#include "Universe.h"

class ExampleLayer : public Universe::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		std::cout << "ExampleLayer::Update" << std::endl;
	}

	void OnEvent(Universe::Event& event) override
	{
		std::cout << "ExampleLayer::Event" << std::endl;
	}
};

class Sandbox : public Universe::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

Universe::Application* Universe::CreateApplication()
{
	return new Sandbox();
}