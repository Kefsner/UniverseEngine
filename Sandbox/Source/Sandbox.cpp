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
		if (Universe::Input::IsKeyPressed(UE_KEY_TAB))
			UE_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Universe::Event& event) override
	{
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