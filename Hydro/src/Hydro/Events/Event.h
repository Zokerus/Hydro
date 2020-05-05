#pragma once
#include "pch.h"

#include "Hydro/Core.h"

namespace Hydro {
	//At this stage the event system is a blocking type, this means a raised event has to handled
	//and dispatched right away. For the future a system with a event queue and a event handler
	//during the update loop is planned

	enum class EventType
	{
		None= 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventApplication	= BIT(0),
		EventInput			= BIT(1),
		EventKeyboard		= BIT(2),
		EventMouse			= BIT(3),
		EventMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HYDRO_API Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFnc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFnc<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;

	friend inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
	};
}