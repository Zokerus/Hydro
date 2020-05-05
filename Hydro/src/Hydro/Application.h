#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hydro {

	class HYDRO_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}