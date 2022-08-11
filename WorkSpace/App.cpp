#include <Engine.hpp>

class ExampleLayer : public Engine::Layer
{
 public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ENGINE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Engine::IEvent& event) override
	{
		ENGINE_TRACE("{0}", event);
	}

};

class WorkSpace : public Engine::Application
{
 public:
	WorkSpace()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Engine::ImGuiLayer());
	}
	virtual ~WorkSpace()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new WorkSpace();
}
