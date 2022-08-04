#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

namespace Engine {

		class Application
		{
		public:
			Application();
			virtual ~Application();

			void Run();
		};

		extern Application* CreateApplication();
}

#endif//ENGINE_ENGINE_H
