#ifndef ENGINE_ENGINE_ENGINE_IMGUI_IMGUILAYER_H_
#define ENGINE_ENGINE_ENGINE_IMGUI_IMGUILAYER_H_

#include "../Layer.hpp"

#include <GLFW/glfw3.h>

namespace Engine
{

	class ImGuiLayer : public Layer
	{
	 public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	 private:
		float m_Time = 0.0f;

	};

} // Engine

#endif //ENGINE_ENGINE_ENGINE_IMGUI_IMGUILAYER_H_
