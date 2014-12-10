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

		_height = radius*2;
		_width = radius * 2;

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
			_vertices.push_back(0.5+testi);

			float testi2 = sin((j * asd * (PI / 180)))/ 2;
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
	void CMCircle::SetTextureRectangle(float x, float y, float widht, float height)
	{
		_textureRectangle.setX(x);
		_textureRectangle.setY(y);
		_textureRectangle.setZ(widht);
		_textureRectangle.setK(height);


		float temp_x = 1 - ((_image->getWidth() - x) / _image->getWidth());
		float temp_widht = 1 - ((_image->getWidth() - widht) / _image->getWidth());
		float temp_y = 1 - ((_image->getHeight() - y) / _image->getHeight());
		float temp_height = 1 - ((_image->getHeight() - height) / _image->getHeight());

		float asd = 360 / _sides;

		for (int i = 1; i < _sides + 1; i++)
		{
			float testi = cos((i * asd * (PI / 180))) / 2;
			_vertices.at(5 + 7 * i) = (0.5 + testi) * temp_widht;

			float testi2 = sin((i * asd * (PI / 180))) / 2;
			_vertices.at(6 + 7 * i) = (0.5 + testi2) * temp_height;
		}

	}
	CMVector4<float> CMCircle::GetTexturectangle()
	{
		return _textureRectangle;
	}
}