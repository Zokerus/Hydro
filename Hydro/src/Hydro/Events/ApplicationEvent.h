#pragma once

#include "Event.h"

namespace Hydro {
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventApplication)
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventApplication)
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventApplication)
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(unsigned int xPosition, unsigned int yPosition)
			: m_PositionX(xPosition), m_PositionY(yPosition) {}

		inline unsigned int GetXPosition() { return m_PositionX; }
		inline unsigned int GetYPosition() { return m_PositionY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << m_PositionX << ", " << m_PositionY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventApplication)

	private:
		unsigned int m_PositionX, m_PositionY;
	};

	class HYDRO_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventApplication)
	};

	class HYDRO_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventApplication)
	};

	class HYDRO_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventApplication)
	};
}