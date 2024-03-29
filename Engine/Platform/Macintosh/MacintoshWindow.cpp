#include "MacintoshWindow.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "OpenGL/OpenGLContext.hpp"

#include <glad/glad.h>

namespace Engine
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		ENGINE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	IWindow* IWindow::Create(const WindowProps& props)
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
		m_Context->SwapBuffers();
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

		ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
		//these are required to set appropriate glsl version.

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ENGINE_CORE_ASSERT(success, "Could not intialize glfw!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

#if defined(__APPLE__)
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#endif



		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);

		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();


		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) -> void
		{
		  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		  data.Width = width;
		  data.Height = height;

		  WindowResizeEvent event(width, height);
		  data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
		  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		  WindowCloseEvent event;
		  data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
		  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		  switch (action)
		  {
		  case GLFW_PRESS:
		  {
			  KeyPressedEvent event(key, 0);
			  data.EventCallback(event);
			  break;
		  }
		  case GLFW_RELEASE:
		  {
			  KeyReleasedEvent event(key);
			  data.EventCallback(event);
			  break;
		  }
		  case GLFW_REPEAT:
		  {
			  KeyPressedEvent event(key, 1);
			  data.EventCallback(event);
			  break;
		  }
		  }
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
		  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		  switch (action)
		  {
		  case GLFW_PRESS:
		  {
			  MouseButtonPressedEvent event(button);
			  data.EventCallback(event);
			  break;
		  }
		  case GLFW_RELEASE:
		  {
			  MouseButtonReleasedEvent event(button);
			  data.EventCallback(event);
			  break;
		  }
		  }
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
		  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		  MouseScrolledEvent event((float)xOffset, (float)yOffset);
		  data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
		  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		  MouseMovedEvent event((float)xPos, (float)yPos);
		  data.EventCallback(event);
		});

	}
	void MacintoshWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}