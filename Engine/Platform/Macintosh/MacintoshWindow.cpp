#include "MacintoshWindow.hpp"

namespace Engine {
	static bool s_GLFWInitialized = false;

	IWindow* IWindow::Create (const WindowProps& props)
	{
		return new MacintoshWindow(props);
	}
	MacintoshWindow::MacintoshWindow(const WindowProps& props)
	{
		Init(props);
	}
	MacintoshWindow::~MacintoshWindow()
	{
		Shutdown();
	}
	void MacintoshWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	void MacintoshWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}
	bool MacintoshWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
	void MacintoshWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

//		ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
//			ENGINE_CORE_ASSERT(success, "Could not intialize glfw!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}
	void MacintoshWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}