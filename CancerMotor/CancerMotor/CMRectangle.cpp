#include "CMRectangle.h"

CMRectangle::CMRectangle(float _x, float _y, float width, float height) : CMShape(_x, _y)
{
	_width = width;
	_height = height;
}
CMRectangle::CMRectangle() : CMShape()
{
	_width = 0;
	_height = 0;
}

CMRectangle::~CMRectangle()
{
}

void CMRectangle::SetWidth(float w)
{
	_width = w;
}
float CMRectangle::GetWidth()
{
	return _width;
}
void CMRectangle::SetHeight(float h)
{
	_height = h;
}
float CMRectangle::GetHeight()
{
	return _height;
}