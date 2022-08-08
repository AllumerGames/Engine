#ifndef ENGINE_ENGINE_ENGINE_EVENTS_APPLICATIONEVENT_H_
#define ENGINE_ENGINE_ENGINE_EVENTS_APPLICATIONEVENT_H_

#include <sstream>
#include "Event.hpp"

namespace Engine {
	class WindowResizeEvent : public IEvent
	{
	 public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const
		{
			return m_Width;
		}

		inline unsigned int GetHeight() const
		{
			return m_Height;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	 private:
		unsigned int m_Width, m_Height;
	};

	struct WindowCloseEvent : public IEvent
	{
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	struct AppTickEvent : public IEvent
	{
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	struct AppUpdateEvent : public IEvent
	{
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	struct AppRenderEvent : public IEvent
	{
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


}

#endif //ENGINE_ENGINE_ENGINE_EVENTS_APPLICATIONEVENT_H_
