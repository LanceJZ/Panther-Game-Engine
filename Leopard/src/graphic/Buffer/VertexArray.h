#pragma once

#include <vector>
#include <GL/glew.h>
#include "Buffer.h"

namespace Leopard
{
	namespace Graphics
	{
		class VertexArray
		{
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void Bind() const;
			void Unbind() const;
		private:
		};
	}
}