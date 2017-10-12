#pragma once

#include <GL/glew.h>

namespace Leopard
{
	namespace Graphics
	{

		class IndexBuffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:
			IndexBuffer(GLushort * data, GLsizei count);
			~IndexBuffer();

			inline GLuint getCount() const { return m_Count; }
			void Bind() const;
			void Unbind() const;
		private:
		};

	}
}