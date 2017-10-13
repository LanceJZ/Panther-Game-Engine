#include "Static_Sprite.h"

namespace Leopard
{
	namespace Graphics
	{
		Static_Sprite::Static_Sprite(Vector3f position, Vector2f size, const Vector4f& color, Shader& shader)
			: Renderable2D(position, size, color), m_Shader(shader)
		{
			m_VertexArray = new VertexArray();

			GLfloat vertices[] =
			{
				0, 0, 0,
				0, size.Y, 0,
				size.X, size.Y, 0,
				size.X, 0, 0
			};

			GLfloat colors[] =
			{
				color.X, color.Y, color.Z, color.W,
				color.X, color.Y, color.Z, color.W,
				color.X, color.Y, color.Z, color.W,
				color.X, color.Y, color.Z, color.W
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0};
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		Static_Sprite::~Static_Sprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}