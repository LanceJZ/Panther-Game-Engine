#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		Renderable2D::Renderable2D(Vector3f position, Vector2f size, Vector4f color, Shader& shader)
			: m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
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

		Renderable2D::~Renderable2D()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}