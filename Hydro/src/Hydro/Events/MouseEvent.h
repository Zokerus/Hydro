#pragma once

#include "Event.h"

#include <sstream>

namespace Hydro {
	class HYDRO_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventMouse | EventInput)
	private:
		float m_MouseX, m_MouseY;
	};
	
	class HYDRO_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_OffsetX(xOffset), m_OffsetY(yOffset) {}

		inline float GetXOffset() const { return m_OffsetX; }
		inline float GetYOffset() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventMouse | EventInput)
	private:
		float m_OffsetX, m_OffsetY;
	};

	class HYDRO_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventMouse | EventInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class HYDRO_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HYDRO_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}