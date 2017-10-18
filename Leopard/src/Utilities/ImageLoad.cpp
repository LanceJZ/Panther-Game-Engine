#include "ImageLoad.h"

namespace Leopard
{
	ImageLoad::ImageLoad()
	{
	}

	ImageLoad::~ImageLoad()
	{

	}
	BYTE * ImageLoad::LoadFile(const char * filename, GLsizei * width, GLsizei * height)
	{
		BYTE * image = nullptr;
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP *dib = nullptr;
		//check the file signature and deduce its format
		fif = FreeImage_GetFileType(filename, 0);
		if(fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(filename);
		if(fif == FIF_UNKNOWN)
			image = nullptr;

		if(FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, filename);
		if(!dib)
			image = nullptr;

		//retrieve the image data
		image = FreeImage_GetBits(dib);
		//get the image width and height
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);

		return image;
	}
}