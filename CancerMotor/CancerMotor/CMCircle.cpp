#include "CMCircle.h"
#include <math.h>
#include <iostream>
#define PI 3.14159265
namespace CML
{
	CMCircle::CMCircle(float _x, float _y, float radius, int sides) : CMShape(_x, _y)
	{
		_radius = radius;
		_sides = sides;

		SetX(_x);
		SetY(_y);

		_rotation = 0;
		_origon.setShitBooleanPaskafixJustForJPCozHeLovesThis(0.0f, 0.0f);

		// First center vertex of triangle fan
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);

		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);
		_vertices.push_back((GLfloat)0);

		_vertices.push_back((GLfloat)0.5f);
		_vertices.push_back((GLfloat)0.5f);

		for (int j = 0; j < _sides; j++)
		{
			_vertices.push_back(radius * cos((j * PI / 180)));
			_vertices.push_back(radius * sin((j * PI / 180)));

			_vertices.push_back((GLfloat)0);
			_vertices.push_back((GLfloat)0);
			_vertices.push_back((GLfloat)0);

			_vertices.push_back(cos((j * PI / 180)));
			_vertices.push_back(sin((j * PI / 180)));
		}

		for (int k = 0; k < 360 / sides - 1; k++)
		{
			_indices.push_back((GLuint)0);
			_indices.push_back((GLuint)k + 1);
			_indices.push_back((GLuint)k + 2);
		}
			_indices.push_back((GLuint)0);
			_indices.push_back((GLuint)360 / sides);
			_indices.push_back((GLuint)1);

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

}