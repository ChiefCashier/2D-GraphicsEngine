#pragma once
#include "CMShape.h"
class CMRectangle :
	public CMShape
{
public:
	CMRectangle(float _x, float _y, float width, float height);
	CMRectangle();
	~CMRectangle();

	void SetWidth(float w);
	float GetWidth();

	void SetHeight(float h);
	float GetHeight();

private:
	float _width, _height;
};