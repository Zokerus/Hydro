#pragma once

#ifdef HD_PLATFORM_WINDOWS

extern Hydro::Application* Hydro::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hydro::CreateApplication();
	app->Run();
	delete app;
}
#endif // HD_PLATFORM_WINDOWS
