#pragma once

#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		class Sprite : public Renderable2D
		{
		private:
			//VertexArray* m_VertexArray;
			//IndexBuffer* m_IndexBuffer;

		public:
			Sprite(Vector3f position, Vector2f size, const Vector4f& color);
			~Sprite();

			inline const Vector3f& getPosition() const { return m_Position; }
			inline const Vector2f& getSize() const { return m_Size; }
			inline const Vector4f& getColor() const { return m_Color; }

			//inline const VertexArray* getVAO() const { return m_VertexArray; }
			//inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		};
	}
}