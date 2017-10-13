#include "Sprite.h"

namespace Leopard
{
	namespace Graphics
	{
		Sprite::Sprite(Vector3f position, Vector2f size, const Vector4f& color)
			: Renderable2D(position, size, color)
		{

		}

		Sprite::~Sprite()
		{

		}
	}
}