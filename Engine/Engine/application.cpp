#include "application.hpp"

#include <GLFW/glfw3.h>

namespace Engine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<IWindow>(IWindow::Create());
		m_Window->SetEventCallback(
			std::bind(&Application::OnEvent, this, std::placeholders::_1)
		);
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(IEvent& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(
			&Application::OnWindowClose, this, std::placeholders::_1)
		);
		ENGINE_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}

