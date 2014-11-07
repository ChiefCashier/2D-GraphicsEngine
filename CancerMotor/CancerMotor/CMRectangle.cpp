#include "CMRectangle.h"

namespace CML
{
	CMRectangle::CMRectangle(float _x, float _y, float width, float height) : CMShape(_x, _y)
	{
		_width = width;
		_height = height;
		_vertices.push_back((GLfloat)_x);
		_vertices.push_back((GLfloat)_y);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0.0f);//rec.GetX());
		_vertices.push_back((GLfloat)0.0f);//rec.GetY() - rec.GetHeight());
		//top right
		_vertices.push_back((GLfloat)_x);
		_vertices.push_back((GLfloat)_y + height);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0.0f);//rec.GetX());
		_vertices.push_back((GLfloat)1.0f);//rec.GetY());
		//bottom right
		_vertices.push_back((GLfloat)_x + width);
		_vertices.push_back((GLfloat)_y + height);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)1.0f);//rec.GetX()+rec.GetWidth());
		_vertices.push_back((GLfloat)1.0f);//rec.GetY());
		//bottom left
		_vertices.push_back((GLfloat)_x + width);
		_vertices.push_back((GLfloat)_y);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)1.0f);//rec.GetX()+ rec.GetWidth());
		_vertices.push_back((GLfloat)0.0f);//rec.GetY() - rec.GetHeight());

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
		_vertices.at(0) = x;
		_vertices.at(7) = x;
		_vertices.at(14) = x + _width;
		_vertices.at(21) = x + _width;
	}

	void CMRectangle::SetY(float y)
	{
		_y = y;
		_vertices.at(1) = y;
		_vertices.at(8) = y + _height;
		_vertices.at(15) = y + _height;
		_vertices.at(22) = y;

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
		_width = w;
		_vertices.at(14) = _x + w;
		_vertices.at(21) = _x + w;
	}
	float CMRectangle::GetWidth()
	{
		return _width;
	}
	void CMRectangle::SetHeight(float h)
	{
		_height = h;
		_vertices.at(8) = _y + h;
		_vertices.at(15) = _y + h;
	}
	float CMRectangle::GetHeight()
	{
		return _height;
	}
}