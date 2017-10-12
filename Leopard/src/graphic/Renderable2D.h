#pragma once

#include "Shader.h"
#include "Buffer\Buffer.h"
#include "Buffer\IndexBuffer.h"
#include "Buffer\VertexArray.h"
#include "..\Math\Math.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Renderable2D
		{
		protected:
			Vector3f m_Position;
			Vector2f m_Size;
			Vector4f m_Color;

			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
			Shader& m_Shader;

		public:
			Renderable2D(Vector3f position, Vector2f size, Vector4f color, Shader& shader);
			virtual ~Renderable2D();

			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
			inline Shader& getShader() const { return m_Shader; }

			inline const Vector3f& getPosition() const { return m_Position; }
			inline const Vector2f& getSize() const { return m_Size; }
			inline const Vector4f& getColor() const { return m_Color; }
		};

	}
}