#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "LayerStack.hpp"

#include "Window.h"

namespace Engine
{

	class Application
	{
	 public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(IEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	 private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<IWindow> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	extern Application* CreateApplication();
}

#endif//ENGINE_ENGINE_H
