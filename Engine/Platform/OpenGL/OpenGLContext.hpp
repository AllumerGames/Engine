
#ifndef ENGINE_ENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_HPP_
#define ENGINE_ENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_HPP_

#include "Renderer/GraphicsContexts.hpp"


struct GLFWwindow;
namespace Engine
{
	class OpenGLContext : public IGraphicsContext
	{
	 public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	 private:
		GLFWwindow* m_WindowHandle;
	};

}

#endif //ENGINE_ENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_HPP_
