#include <Engine.hpp>

Engine::Application* Engine::CreateApplication()
{
	return new Application();
}
