#pragma once

#include <string>
#include <FreeImage.h>
#include <GL/glew.h>

namespace Leopard
{
	static class ImageLoad
	{
	public:
		ImageLoad();
		~ImageLoad();

		static BYTE* LoadFile(const char* filename, GLsizei* width, GLsizei* height);
	};

}