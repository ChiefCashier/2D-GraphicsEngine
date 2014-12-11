#include "CMShape.h"

namespace CML
{
	CMShape::CMShape(float x, float y)
	{
		_x = x;
		_y = y;
		_rotation = 0;
		_origon.setShitBooleanPaskafixJustForJPCozHeLovesThis(0.0f, 0.0f);
		_size.setShitBooleanPaskafixJustForJPCozHeLovesThis(1.0f, 1.0f);
		_hasImage = false;
	}
	CMShape::CMShape()
	{
		_x = 0;
		_y = 0;
		_rotation = 0;
		_origon.setShitBooleanPaskafixJustForJPCozHeLovesThis(0.0f, 0.0f);
		_size.setShitBooleanPaskafixJustForJPCozHeLovesThis(1.0f, 1.0f);
		_hasImage = false;
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
	int CMShape::GetRotation()
	{
		return _rotation;
	}
	void CMShape::SetColor(vec4 color)
	{
		for (int i = 0; i < 4; i++)
		{
			_colorRGBA[i] = color[i];
		}
	}

	void CMShape::SetWidth(float w)
	{
		float temp_width = _size.getX() * (w / _width);
		_width = w;
		_size.setX(temp_width);
	}

	float CMShape::GetWidth()
	{
		return _width;
	}

	void CMShape::SetHeight(float h)
	{
		float temp_height = _size.getY() * (h / _height);
		_height = h;
		_size.setY(temp_height);
	}
	float CMShape::GetHeight()
	{
		return _height;
	}
	void CMShape::SetColor(float r, float b, float g, float a)
	{
		_colorRGBA[0] = r;
		_colorRGBA[1] = b;
		_colorRGBA[2] = g;
		_colorRGBA[3] = a;
	}
	float CMShape::GetColorR()
	{
		return _colorRGBA[0];
	}
	float CMShape::GetColorG()
	{
		return _colorRGBA[1];
	}
	float CMShape::GetColorB()
	{
		return _colorRGBA[2];
	}
	float CMShape::GetColorA()
	{
		return _colorRGBA[3];
	}
	void CMShape::SetSize(float s)
	{
		_size.setX(s);
		_size.setY(s);
	}

	CMVector2<float> CMShape::GetSize()
	{
		return _size;
	}

	void CMShape::SetOrigon(float x, float y)
	{
		_origon.setX(x);
		_origon.setY(y);
	}
	CMVector2<float> CMShape::GetOrigon()
	{
		return _origon;
	}
	std::vector<GLfloat> &CMShape::GetVertices()
	{
		return _vertices;
	}
	std::vector<GLuint> &CMShape::GetIndices()
	{
		return _indices;
	}
	CMImage* CMShape::GetImage()
	{
		return _image;
	}
	void CMShape::SetImage(char* path)
	{
		_image = new CMImage(path);
		_hasImage = true;
	}
	void CMShape::SetImage(CMImage *image)
	{
		_image = image;
		_hasImage = true;
	}
	CMVector2<float> CMShape::GetPosition()
	{
		return CMVector2<float>(GetX(), GetY());
	}
}