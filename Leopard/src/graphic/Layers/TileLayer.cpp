#include "TileLayer.h"

namespace Leopard
{
	namespace Graphics
	{
		TileLayer::TileLayer(Shader* shader)
			: Layer(new BatchedRenderer2D(), shader, Matrix::Orthographic(-400.0f, 400.0f, -300.0f, 300.0f, -10.0f, 10.0f))
		{
		}


		TileLayer::~TileLayer()
		{
		}
	}
}