#pragma once
#include "CMShape.h"
namespace CML
{
	class CMRectangle : public CMShape
	{
	public:

		CMRectangle(float _x, float _y, float width, float height);
		CMRectangle();
		~CMRectangle();

		void SetX(float x);
		void SetY(float y);

		void SetWidth(float w);
		float GetWidth();

		void SetHeight(float h);
		float GetHeight();

		void SetColor(vec4 color);
		void SetColor(float r, float b, float g, float a);

	private:

		float _width, _height;
	};
}