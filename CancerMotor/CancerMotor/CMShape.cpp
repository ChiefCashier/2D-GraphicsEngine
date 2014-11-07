#include "CMShape.h"
namespace CML
{
	CMShape::CMShape(float x, float y)
	{
		_x = x;
		_y = y;
	}
	CMShape::CMShape()
	{
		_x = 0;
		_y = 0;
		_rotation = 0;
		_origon = 0;
		_colorRGBA[0] = 0;
		_colorRGBA[1] = 0;
		_colorRGBA[2] = 0;
		_colorRGBA[3] = 255;
		_size = 1;
	}
	CMShape::~CMShape()
	{
	}

	void CMShape::SetX(float x)
	{
		_x = x;
		_vertices.at(0) = x;
	}
	float CMShape::GetX()
	{
		return _x;
	}

	void CMShape::SetY(float y)
	{
		_y = y;
		_vertices.at(1) = y;
	}
	float CMShape::GetY()
	{
		return _y;
	}

	void CMShape::SetRotation(int a)
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
		_size = s;
	}
	float CMShape::GetSize()
	{
		return _size;
	}

	void CMShape::SetOrigon(float x, float y)
	{
		//_origon = x & y; 
		// todo
	}
	float CMShape::GetOrigon()
	{
		return _origon;
	}
	std::vector<GLfloat> CMShape::GetVertices()
	{
		return _vertices;
	}
	std::vector<GLuint> CMShape::GetIndices()
	{
		return _indices;
	}
	CMImage CMShape::GetImage()
	{
		return _image;
	}
	void CMShape::SetImage(char* path)
	{
		_image = CMImage::CMImage(path);
	}

}