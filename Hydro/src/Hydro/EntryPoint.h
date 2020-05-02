#pragma once

#ifdef HD_PLATFORM_WINDOWS

extern Hydro::Application* Hydro::CreateApplication();

int main(int argc, char** argv)
{
	Hydro::Log::Init();
	Hydro::Log::GetCoreLogger()->warn("Initialized Log!");
	Hydro::Log::GetClientLogger()->info("Hello!");

	auto app = Hydro::CreateApplication();
	app->Run();
	delete app;
}
#endif // HD_PLATFORM_WINDOWS
