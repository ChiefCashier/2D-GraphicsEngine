#pragma once
#include <vector>
#include "glew.h"
#include "CMImage.h"

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

		void SetRotation(int a);
		int GetRotation();

		void SetColor(vec4 color);
		void SetColor(float r, float b, float g, float a);

		float GetColorR();
		float GetColorG();
		float GetColorB();
		float GetColorA();

		void SetSize(float s);
		float GetSize();

		void SetOrigon(float x, float y);
		float GetOrigon();

		std::vector<GLfloat> &GetVertices();
		std::vector<GLuint> &GetIndices();

		CMImage* GetImage();
		void SetImage(char* path);
		void SetImage(CMImage *image);

	protected:

		float _x, _y, _origon, _size;
		int _rotation;
		vec4 _colorRGBA;

		CMImage *_image;

		std::vector<GLfloat> _vertices;
		std::vector<GLuint> _indices;
	};
}