#ifndef ENGINE_ENGINE_PLATFORM_MACINTOSH_MACINTOSHWINDOW_H_
#define ENGINE_ENGINE_PLATFORM_MACINTOSH_MACINTOSHWINDOW_H_

#include "../../Engine/Window.h"
#include <GLFW/glfw3.h>

namespace Engine{

	class MacintoshWindow : public IWindow
	{
	 public:
		MacintoshWindow(const WindowProps& props);
		virtual ~ MacintoshWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	 private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	 private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		GLFWwindow* m_Window;
		WindowData m_Data;

	};

}

#endif //ENGINE_ENGINE_PLATFORM_MACINTOSH_MACINTOSHWINDOW_H_
