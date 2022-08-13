#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "LayerStack.hpp"

#include "Window.h"

#include "ImGui/ImGuiLayer.hpp"

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

		inline IWindow& GetWindow()
		{
			return *m_Window;
		}

		inline static Application& Get()
		{
			return *s_Instance;
		}
	 private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<IWindow> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	 private:
		static Application* s_Instance;
	};

	extern Application* CreateApplication();
}

#endif//ENGINE_ENGINE_H
