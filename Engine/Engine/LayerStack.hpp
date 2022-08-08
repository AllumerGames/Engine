#ifndef ENGINE_ENGINE_ENGINE_LAYERSTACK_H_
#define ENGINE_ENGINE_ENGINE_LAYERSTACK_H_

#include "Layer.hpp"

namespace Engine
{

	class LayerStack
	{
		using v_Layer = std::vector<Layer*>;
	 public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		v_Layer::iterator begin()
		{
			return m_Layers.begin();
		}
		v_Layer::iterator end()
		{
			return m_Layers.end();
		}

	 private:
		v_Layer m_Layers;
		v_Layer::iterator m_LayerInsert;

	};

} //Engine
#endif //ENGINE_ENGINE_ENGINE_LAYERSTACK_H_
