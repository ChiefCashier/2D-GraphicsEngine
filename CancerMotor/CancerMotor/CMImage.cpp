#include "CMImage.h"
#include <assert.h>
#include <string>
#include <iostream>
namespace CML
{
	CMImage::CMImage(char* name) :Resource(name)
	{
		FREE_IMAGE_FORMAT formato = FreeImage_GetFIFFromFilename(name);
		FIBITMAP* imagen = FreeImage_Load(formato, name);
		_name = name;
		_width = FreeImage_GetWidth(imagen);
		_height = FreeImage_GetHeight(imagen);
		void* pixeles = static_cast<void*>(FreeImage_GetBits(imagen));
		//rename a
		FREE_IMAGE_TYPE a = FreeImage_GetImageType(imagen);
		assert(a == FIT_BITMAP || a == FIT_RGB16);
		if (a != FIT_BITMAP)
		{
			//handle error
		}
		if (a == FIT_RGB16)
		{
			imagen = FreeImage_ConvertTo32Bits(imagen);
			a = FreeImage_GetImageType(imagen);
		}
		unsigned int bitDepth= FreeImage_GetBPP(imagen);
		assert(bitDepth == 24 || bitDepth == 32 || bitDepth == 48);
		//handle error
		_pixelData = pixeles;

		/*
		Tarkoittaa 
		if(bitDepth == 24)
		_ImageFormat = GL_RGB;
		else
		_ImageFOrmat = GL_RGBA;
		*/
		switch (bitDepth)
		{
		case 24:
			_imageFormat = GL_BGR;
			break;
		case 32:
			_imageFormat = GL_BGRA;
			break;
		case 48:
			_imageFormat = GL_BGR;
			break;
		}
		//_imageFormat = bitDepth == 24 ? GL_RGB : GL_BGRA;

		glGenTextures(1, &_textureId);//generates texture
		glBindTexture(GL_TEXTURE_2D,_textureId);

		glTexImage2D(
						GL_TEXTURE_2D, 0, 4, _width,
						_height, 0, _imageFormat,
						GL_UNSIGNED_BYTE, FreeImage_GetBits(imagen)
						);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D,0u);
		FreeImage_Unload(imagen);


	}

	FIBITMAP* CMImage::getBITMAP()
	{
		FREE_IMAGE_FORMAT formato = FreeImage_GetFIFFromFilename(_name);
		return FreeImage_Load(formato, _name);
	}
	CMImage::~CMImage()
	{
		glDeleteTextures(1, &_textureId);
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
	GLuint CMImage::getTextureId()
	{
		return _textureId;
	}
}