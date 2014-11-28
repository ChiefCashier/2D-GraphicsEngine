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

		float asd = 360 / _sides;
		for (int j = 0; j < _sides+1; j++)
		{
			float y = radius * cos((1 * asd));
			_vertices.push_back(radius * cos( (j * asd * (PI / 180) ) ) );
			_vertices.push_back(radius * sin( (j * asd * (PI / 180) ) ) );

			_vertices.push_back((GLfloat)0);
			_vertices.push_back((GLfloat)0);
			_vertices.push_back((GLfloat)0);

			float testi = cos((j * asd * (PI / 180)))/ 2;

			if (testi >= 0)
				_vertices.push_back(0.5+testi);
			else
				_vertices.push_back(0.5+testi);

			float testi2 = sin((j * asd * (PI / 180)))/ 2;

			if (testi2 >= 0)
				_vertices.push_back(0.5+testi2);
			else
				_vertices.push_back(0.5+testi2);

		
		}


		for (int k = 0; k < sides-1; k++)
		{
			_indices.push_back((GLuint)0);
			_indices.push_back((GLuint)k + 1);
			_indices.push_back((GLuint)k + 2);
		}
			_indices.push_back((GLuint)0);
			_indices.push_back((GLuint)sides);
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