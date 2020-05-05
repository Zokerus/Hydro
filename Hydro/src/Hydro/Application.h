#pragma once

#include "Core.h"
#include "Hydro/Events/Event.h"
#include "Hydro/Events/ApplicationEvent.h"
#include "Hydro/LayerStack.h"
#include "Window.h"

namespace Hydro {

	class HYDRO_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}