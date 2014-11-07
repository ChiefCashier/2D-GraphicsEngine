#include "CMCircle.h"
namespace CML
{
	CMCircle::CMCircle(float _x, float _y, float radius, int sides) : CMShape(_x, _y)
	{
		_radius = radius;
		_sides = sides;

		// First center vertex of triangle fan
		_vertices.push_back((GLfloat)_x);
		_vertices.push_back((GLfloat)_y);

		_vertices.push_back((GLfloat)1);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);

		_vertices.push_back((GLfloat)0.0f);
		_vertices.push_back((GLfloat)0.0f);

		_indices.push_back((GLuint)0);

		for (int i = 1; i < sides; i++)
		{
			_indices.push_back((GLuint)i);

			_vertices.push_back(_x + radius * cos(i));
			_vertices.push_back(_y + radius * sin(i));

			_vertices.push_back((GLfloat)1);
			_vertices.push_back((GLfloat)0);
			_vertices.push_back((GLfloat)0);

			_vertices.push_back((GLfloat)0);
			_vertices.push_back((GLfloat)0);
		}
	}

	CMCircle::~CMCircle()
	{
	}

	void CMCircle::SetSides(int s)
	{
		_sides = s;
	}

	int CMCircle::GetSides()
	{
		return _sides;
	}

	void CMCircle::SetRadius(int r)
	{
		_radius = r;
	}

	int CMCircle::GetRadius()
	{
		return _radius;
	}
	void CMCircle::SetColor(float r, float g, float b, float a)
	{
		_colorRGBA[0] = r;
		_colorRGBA[1] = g;
		_colorRGBA[2] = b;
		_colorRGBA[3] = a;

		for (int i = 0; i < _sides + 1; i++)
		{
	 			_vertices.at(2 + i * 7) = r;
			_vertices.at(3 + i * 7) = g;
			_vertices.at(4 + i * 7) = b;
		}
	}
}