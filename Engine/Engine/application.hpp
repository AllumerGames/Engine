#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Events/Event.hpp"
#include "Window.h"

namespace Engine {

		class Application
		{
		 public:
			Application();
			virtual ~Application();

			void Run();
		 private:
			std::unique_ptr<IWindow> m_Window;
			bool m_Running = true;
		};

		extern Application* CreateApplication();
}

#endif//ENGINE_ENGINE_H
