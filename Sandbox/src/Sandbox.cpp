#include <Hydro.h>

class ExampleLayer : public Hydro::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override
	{
		HD_INFO("Example Layer::Update");
	}

	void OnEvent(Hydro::Event& event) override
	{
		HD_TRACE("{0}", event);
	}
};


class Sandbox : public Hydro::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hydro::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Hydro::Application* Hydro::CreateApplication()
{
	return new Sandbox();
}