#ifndef ENGINE_ENGINE_ENGINE_RENDERER_GRAPHICSCONTEXTS_HPP_
#define ENGINE_ENGINE_ENGINE_RENDERER_GRAPHICSCONTEXTS_HPP_

namespace Engine
{
	class IGraphicsContext
	{
	 public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}

#endif //ENGINE_ENGINE_ENGINE_RENDERER_GRAPHICSCONTEXTS_HPP_
