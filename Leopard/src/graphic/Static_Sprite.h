#pragma once

#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		class Static_Sprite : Renderable2D
		{
		private:
			Shader& m_Shader;
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;


		public:
			Static_Sprite(Vector3f position, Vector2f size, const Vector4f& color, Shader& shader);
			~Static_Sprite();

			inline const Vector3f& getPosition() const { return m_Position; }

			inline Shader& getShader() const { return m_Shader; }

			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		};

	}
}