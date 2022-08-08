#ifndef ENGINE_ENGINE_ENGINE_LAYER_HPP_
#define ENGINE_ENGINE_ENGINE_LAYER_HPP_

#include "Events/Event.hpp"

namespace Engine
{

	class Layer
	{
	 public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach()
		{
		}
		virtual void OnDetach()
		{
		}
		virtual void OnUpdate()
		{
		}
		virtual void OnEvent(IEvent& event)
		{
		}

		inline const std::string& GetName() const
		{
			return m_DebugName;
		}

	 protected:
		std::string m_DebugName;
	};

} // Engine

#endif //ENGINE_ENGINE_ENGINE_LAYER_HPP_
