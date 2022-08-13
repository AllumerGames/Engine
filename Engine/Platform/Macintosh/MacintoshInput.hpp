//
// Created by 김원진 on 2022/08/13.
//

#ifndef ENGINE_ENGINE_PLATFORM_MACINTOSH_MACINTOSHINPUT_HPP_
#define ENGINE_ENGINE_PLATFORM_MACINTOSH_MACINTOSHINPUT_HPP_

#include "Input.hpp"

namespace Engine
{
	class MacintoshInput : public Input
	{
	 protected:
		bool IsKeyPressedImpl(int keycode) override;
		bool IsMouseButtonPressedImpl(int button) override;
		std::pair<float, float> GetMousePositionImpl() override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
	};

}

#endif //ENGINE_ENGINE_PLATFORM_MACINTOSH_MACINTOSHINPUT_HPP_
