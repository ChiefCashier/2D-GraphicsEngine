#include "CMShape.h"


CMShape::CMShape()
{
}


CMShape::~CMShape()
{
}

void CMShape::SetX(float x)
{
	_x = x;
}
float CMShape::GetX()
{
	return _x;
}

void CMShape::SetY(float y)
{
	_y = y;
}
float CMShape::GetY()
{
	return _y;
}

void CMShape::SetRotation(float a)
{
	_rotation = a;
}
float CMShape::GetY()
{
	return _rotation;
}

void CMShape::SetColor(float color)
{
	_color = color;
}
float CMShape::GetColor()
{
	return _color;
}

void CMShape::SetSize(int s)
{
	_size = s;
}
int CMShape::GetSize()
{
	return _size;
}

void CMShape::SetOrigon(float x, float y)
{
	//_origon = x & y; 
}
float CMShape::GetOrigon()
{
	return _origon;
}