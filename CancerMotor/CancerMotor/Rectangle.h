#pragma once
#include "CMShape.h"
class Rectangle :
	public CMShape
{
public:
	Rectangle();
	~Rectangle();

	void SetWidth(float w);
	float GetWidth();

	void SetHeight(float h);
	float GetHeight();

private:
	float _width, _height;
};