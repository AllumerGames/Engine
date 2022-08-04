#ifndef ENGINE_ENTRYPOINT_H
#define ENGINE_ENTRYPOINT_H

int main(int argc, char** argv)
{
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif//ENGINE_ENTRYPOINT_H


