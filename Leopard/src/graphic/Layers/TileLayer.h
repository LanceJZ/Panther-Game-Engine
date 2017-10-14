#pragma once

#include "Layer.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class TileLayer : public Layer
		{
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};

	}
}