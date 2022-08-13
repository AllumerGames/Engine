//
// Created by 김원진 on 2022/08/06.
//

#ifndef ENGINE_ENGINE_ENGINE_WINDOW_HPP_
#define ENGINE_ENGINE_ENGINE_WINDOW_HPP_

#include <string>
#include "Events/Event.hpp"

namespace Engine
{
	struct WindowProps
	{
		WindowProps(const std::string& title = "Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}

		std::string Title;
		unsigned int Width;
		unsigned int Height;
	};

	class IWindow
	{
	 public:
		using EventCallbackFn = std::function<void(IEvent&)>;

		virtual ~IWindow()
		{
		}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static IWindow* Create(const WindowProps& prop = WindowProps());

		virtual void* GetNativeWindow() const = 0;
	};
}

#endif //ENGINE_ENGINE_ENGINE_WINDOW_HPP_
