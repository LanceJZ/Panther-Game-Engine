#include "BatchedRenderer2D.h"

namespace Leopard
{
	namespace Graphics
	{
		BatchedRenderer2D::BatchedRenderer2D()
		{
			Initialize();
		}

		BatchedRenderer2D::~BatchedRenderer2D()
		{
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);
		}

		void BatchedRenderer2D::Begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void BatchedRenderer2D::Submit(const Sprite * renderable) // Ep 9 1:10
		{
			const Vector3f &position = renderable->getPosition();
			const Vector2f &size = Vector2f(renderable->getSize().X * 0.5f, renderable->getSize().Y * 0.5f);
			const Vector4f &color = renderable->getColor();

			m_Buffer->vertex = Vector3f(position.X - size.X, position.Y - size.Y, position.Z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = Vector3f(position.X - size.X, position.Y + size.Y, position.Z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = Vector3f(position.X + size.X, position.Y + size.Y, position.Z);
			m_Buffer->color = color;
			m_Buffer++;

			m_Buffer->vertex = Vector3f(position.X + size.X, position.Y - size.Y, position.Z);
			m_Buffer->color = color;
			m_Buffer++;

			m_IndexCount += 6;
		}

		void BatchedRenderer2D::Flush()
		{
			glBindVertexArray(m_VAO);
			m_IBO->Bind();

			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

			m_IBO->Unbind();
			glBindVertexArray(NULL);
			m_IndexCount = 0;
		} //Ep 9 1:30 class done.

		void BatchedRenderer2D::End()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, NULL);
		}

		void BatchedRenderer2D::Initialize()
		{
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*) 0);
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*) (3 * sizeof(GLfloat)));
			glBindBuffer(GL_ARRAY_BUFFER, NULL);

			GLushort indices[RENDERER_INDICES_SIZE];

			int offset = 0;

			for (int i = 0; i < RENDERER_INDICES_SIZE; i+=6)
			{
				indices[i] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;
				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;

				offset += 4;

			}

			m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

			glBindVertexArray(NULL); //54:04 Ep 9
		}
	}
}