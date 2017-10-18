#pragma once

#include <FreeImage.h>
#include <string>
#include <GL/glew.h>
#include "../Utilities/ImageLoad.h"

namespace Leopard
{
	namespace Graphics
	{
		class Texture
		{
		private:
			std::string m_FileName;
			GLuint m_TID;
			GLsizei m_Width, m_Height;

		public:
			Texture(const std::string& filename);
			~Texture();

			void Bind() const;
			void Unbind() const;

			inline const unsigned int getWidth() const { return m_Width; }
			inline const unsigned int getHeight() const { return m_Height; }
			inline const GLuint getID() const { return m_TID; }
		private:
			GLuint Load();

		};
	}
}