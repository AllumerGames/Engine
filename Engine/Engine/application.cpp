#include "application.hpp"

#include "Events/ApplicationEvent.hpp"

#include <GLFW/glfw3.h>

namespace Engine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<IWindow>(IWindow::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while(m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}

