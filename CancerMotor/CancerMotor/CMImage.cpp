#include "CMImage.h"
#include <assert.h>
#include <string>
#include <iostream>
namespace CML
{
	CMImage::CMImage(char* name)
	{
		FREE_IMAGE_FORMAT formato = FreeImage_GetFIFFromFilename(name);
		FIBITMAP* imagen = FreeImage_Load(formato, name);
		_name = name;
		_width = FreeImage_GetWidth(imagen);
		_height = FreeImage_GetHeight(imagen);
		void* pixeles = (void*)FreeImage_GetBits(imagen);
		//rename a
		FREE_IMAGE_TYPE a = FreeImage_GetImageType(imagen);
		assert(a == FIT_BITMAP);
		if (a != FIT_BITMAP)
		{
			//handle error
		}
		unsigned int bitDepth= FreeImage_GetBPP(imagen);
		assert(bitDepth == 24 || bitDepth == 32);
		//handle error
		_pixelData = pixeles;

		/*
		Tarkoittaa 
		if(bitDepth == 24)
		_ImageFormat = GL_RGB;
		else
		_ImageFOrmat = GL_RGBA;
		*/
		_imageFormat = bitDepth == 24 ? GL_RGB : GL_RGBA;
		unsigned int aa = GL_RGBA;
		FreeImage_Unload(imagen);
	}

	FIBITMAP* CMImage::getBITMAP()
	{
		FREE_IMAGE_FORMAT formato = FreeImage_GetFIFFromFilename(_name);
			return FreeImage_Load(formato, _name);
	}
	CMImage::~CMImage()
	{
	}
	size_t CMImage::getWidth()
	{
		return _width;
	}
	size_t CMImage::getHeight()
	{
		return _height;
	}
	char* CMImage::getName()
	{
		return _name;
	}
	void* CMImage::getPixelData()
	{
		return _pixelData;
	}
	GLuint CMImage::getImageFormat()
	{
		return _imageFormat;
	}
}