#include "Sprite.h"

namespace Leopard
{
	namespace Graphics
	{
		Sprite::Sprite(Vector3f position, Vector2f size, const Vector4f& color)
			: Renderable2D(position, size, color)
		{

		}

		Sprite::Sprite(Vector3f position, Vector2f size, Texture * texture)
			: Renderable2D(position, size, Vector4f(0, 0, 1, 1))
		{
			m_Texture = texture;
		}

		Sprite::~Sprite()
		{

		}
	}
}