#pragma once

#include <GL/glew.h>

namespace Leopard
{
	namespace Graphics
	{
		class Buffer
		{
		public:
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;

		public:
			Buffer(GLfloat * data, GLsizei count, GLuint componentCount);
			~Buffer();

			void Bind() const;
			void Unbind() const;

			inline GLuint getComponentCount() const { return m_ComponentCount; }
		};
	}
}