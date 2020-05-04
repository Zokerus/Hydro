#include "pch.h"

#include "Application.h"


#include "Hydro/Events/ApplicationEvent.h"
#include "Hydro/Log.h"

namespace Hydro {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventApplication))
		{
			HD_TRACE(e);
		}
		if (e.IsInCategory(EventInput))
		{
			HD_TRACE(e);
		}
		while (true);
	}
}