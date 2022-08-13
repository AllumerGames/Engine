#include <Engine.hpp>

#include "imgui.h"

class ExampleLayer : public Engine::Layer
{
 public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if(Engine::Input::IsKeyPressed(ENGINE_KEY_TAB))
		{
			ENGINE_TRACE("Tab key is pressed !");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Engine::IEvent& event) override
	{
//		if(event.GetEventType() == Engine::EventType::KeyPressed)
//		{
//			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&) event;
//			if(e.GetKeyCode() == ENGINE_KEY_TAB)
//				ENGINE_TRACE("Tab Key is pressed (event)!");
//			ENGINE_TRACE("{0}",(char)e.GetKeyCode());
//		}
	}

};

class WorkSpace : public Engine::Application
{
 public:
	WorkSpace()
	{
		PushLayer(new ExampleLayer());
//		PushOverlay(new Engine::ImGuiLayer());
	}
	virtual ~WorkSpace()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new WorkSpace();
}
