#pragma once
#include "FreeImage.h"
#include "glew.h"
namespace CML
{
	class CMImage
	{
	public:
		CMImage(char* name);
		~CMImage();
		size_t getWidth();
		size_t getHeight();
		char* getName();
		void* getPixelData();
		GLuint getImageFormat();
		FIBITMAP* getBITMAP();
	private:
		char* _name;
		size_t _width;
		size_t _height;
		void* _pixelData;
		GLuint _imageFormat;
	};

}