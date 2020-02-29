#pragma once

#include "Core/Core.h"
#include "Core/Time.h"
#include "Events/Event.h"

namespace Elion {

	class ELION_API Layer
	{

	public:

		virtual void init(){}
		virtual void update(){}
		virtual void render(){}
		virtual void clear(){}
	};



	class ELION_API LayerState
	{
	private:
		Layer* layer;

	public:

		void set_layer(Layer* layer)
		{
			this->layer = nullptr;

			this->layer = layer;

			this->layer->init();
		}


		void update()
		{
			if (this->layer != nullptr)
			{
				this->layer->update();
			}
		}


		void render()
		{
			if (this->layer != nullptr)
			{
				this->layer->render();
			}
		}


		~LayerState()
		{
			this->layer->clear();
			this->layer = nullptr;
		}
	};

	extern LayerState state;
}