#pragma once
#include "FreeImage.h"
#include "glew.h"
#include "Resource.h"
namespace CML
{
	class CMImage
		:public Resource
	{
	public:
		CMImage():Resource(""){};
		CMImage(char* name);
		CMImage(char* name, int startX, int startY, int width, int height);
		~CMImage();
		size_t getWidth();
		size_t getHeight();
		char* getName();
		void* getPixelData();
		GLuint getImageFormat();
		FIBITMAP* getBITMAP();
		GLuint getTextureId();
	private:
		GLuint _textureId;
		char* _name;
		size_t _width;
		size_t _height;
		void* _pixelData;
		GLuint _imageFormat;

	};

}