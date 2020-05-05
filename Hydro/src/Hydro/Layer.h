#pragma once

#include "Hydro/Core.h"
#include "Hydro/Events/Event.h"

namespace Hydro {
	class HYDRO_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string GetName() { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}