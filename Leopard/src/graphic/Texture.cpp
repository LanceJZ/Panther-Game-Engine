#include "Texture.h"

namespace Leopard
{
	namespace Graphics
	{
		Texture::Texture(const std::string & filename)
			: m_FileName(filename)
		{
			m_TID = Load();
		}

		Texture::~Texture()
		{

		}

		void Texture::Bind() const
		{
			glBindTexture(GL_TEXTURE_2D, m_TID);
		}

		void Texture::Unbind() const
		{
			glBindTexture(GL_TEXTURE_2D, NULL);
		}

		GLuint Texture::Load()
		{
			BYTE *pixels;

			pixels = ImageLoad::LoadFile(m_FileName.c_str(), &m_Width, &m_Height);

			GLuint result;
			glGenTextures(1, &result);
			glBindTexture(GL_TEXTURE_2D, result);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, NULL, GL_RGB, m_Width, m_Height, NULL, GL_BGR, GL_UNSIGNED_BYTE, pixels);
			glBindTexture(GL_TEXTURE_2D, result);

			return result;
		}
	}
}