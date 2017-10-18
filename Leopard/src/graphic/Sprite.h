#pragma once

#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		class Sprite : public Renderable2D
		{
		private:

		public:
			Sprite(Vector3f position, Vector2f size, const Vector4f& color);
			Sprite(Vector3f position, Vector2f size, Texture* texture);
			~Sprite();

			inline const Vector3f& getPosition() const { return m_Position; }
			inline const Vector2f& getSize() const { return m_Size; }
			inline const Vector4f& getColor() const { return m_Color; }
		};
	}
}