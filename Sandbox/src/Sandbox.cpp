#include <Hydro.h>

class Sandbox : public Hydro::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Hydro::Application* Hydro::CreateApplication()
{
	return new Sandbox();
}