#pragma once
#include <vector>
#include "glew.h"
#include "CMImage.h"
#include "CMVector2.h"
#include "CMVector4.h"

namespace CML
{
	class CMShape
	{
	public:
		typedef float vec4[4];

		CMShape(float x, float y);
		CMShape();
		~CMShape();

		void SetX(float x);
		float GetX();

		void SetY(float y);
		float GetY();

		void SetRotation(float a);
		int GetRotation();

		void SetColor(vec4 color);
		void SetColor(float r, float b, float g, float a);

		float GetColorR();
		float GetColorG();
		float GetColorB();
		float GetColorA();

		void SetSize(float s);
		CMVector2<float> GetSize();

		void SetOrigon(float x, float y);
		CMVector2<float> GetOrigon();

		std::vector<GLfloat> &GetVertices();
		std::vector<GLuint> &GetIndices();

		void SetWidth(float w);
		float GetWidth();

		void SetHeight(float h);
		float GetHeight();

		CMImage* GetImage();
		void SetImage(char* path);
		void SetImage(CMImage *image);
		CMVector2<float> GetPosition();
		

	protected:

		float _x, _y;
		float _width, _height;

		CMVector2<float> _size;
		CMVector2<float> _origon;

		CMVector4<float> _textureRectangle;

		int _rotation;
		vec4 _colorRGBA;

		CMImage *_image;

		std::vector<GLfloat> _vertices;
		std::vector<GLuint> _indices;
	};
}