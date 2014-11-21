#include "CMRectangle.h"

namespace CML
{
	CMRectangle::CMRectangle(float _x, float _y, float width, float height) : CMShape(_x, _y)
	{
		_width = width;
		_height = height;
		SetX(_x);
		SetY(_y);
		
		_rotation = 0.0f;
		_origon.setShitBooleanPaskafixJustForJPCozHeLovesThis(0.0f, 0.0f);

		SetSize(1);

		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0.0f);
		_vertices.push_back((GLfloat)0.0f);
		//top right
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)height);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0.0f);
		_vertices.push_back((GLfloat)1.0f);
		//bottom right
		_vertices.push_back((GLfloat)width);
		_vertices.push_back((GLfloat)height);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)-1.0f);
		_vertices.push_back((GLfloat)1.0f);
		//bottom left
		_vertices.push_back((GLfloat)width);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)-1.0f);
		_vertices.push_back((GLfloat)0.0f);

		_indices.push_back(0u);
		_indices.push_back(1u);
		_indices.push_back(2u);
		_indices.push_back(2u);
		_indices.push_back(3u);
		_indices.push_back(0u);
	}
	CMRectangle::CMRectangle() : CMShape()
	{
		CMRectangle(0, 0, 0, 0);
	}

	CMRectangle::~CMRectangle()
	{
	}
	void CMRectangle::SetX(float x)
	{
		_x = x;
	}

	void CMRectangle::SetY(float y)
	{
		_y = y;
	}

	void CMRectangle::SetColor(vec4 color)
	{
		for (int i = 0; i < 4; i++)
		{
			_colorRGBA[i] = color[i];
		}

		for (int j = 0; j < 4; j++)
		{
			_vertices.at(2 + j * 7) = color[0];
			_vertices.at(3 + j * 7) = color[1];
			_vertices.at(4 + j * 7) = color[2];
		}
	}
	void CMRectangle::SetColor(float r, float g, float b, float a)
	{
		_colorRGBA[0] = r;
		_colorRGBA[1] = g;
		_colorRGBA[2] = b;
		_colorRGBA[3] = a;

		for (int i = 0; i < 4; i++)
		{
			_vertices.at(2 + i * 7) = r;
			_vertices.at(3 + i * 7) = g;
			_vertices.at(4 + i * 7) = b;
		}
	}
	void CMRectangle::SetWidth(float w)
	{
		float temp_width = _size.getX() * (w / _width);
		_width = w;
		_size.setX(temp_width);
	}
	float CMRectangle::GetWidth()
	{

		return _width;
	}
	void CMRectangle::SetHeight(float h)
	{
		float temp_height = _size.getX() * (h / _width);
		_height = h;
		_size.setY(temp_height);
	}
	float CMRectangle::GetHeight()
	{
		return _height;
	}
}