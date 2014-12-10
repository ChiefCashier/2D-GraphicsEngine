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
		CMShape::~CMShape();
	}
	void CMRectangle::SetX(float x)
	{
		_x = x;
	}

	void CMRectangle::SetY(float y)
	{
		_y = y;
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
		float temp_height = _size.getY() * (h / _width);
		_height = h;
		_size.setY(temp_height);
	}
	float CMRectangle::GetHeight()
	{
		return _height;
	}
	void CMRectangle::SetTextureRectangle(float x, float y, float widht, float height)
	{
		_textureRectangle.setX(x);
		_textureRectangle.setY(y);
		_textureRectangle.setZ(widht);
		_textureRectangle.setK(height);

		
		float temp_x = 1 - ((_image->getWidth() - x) / _image->getWidth());
		float temp_widht = 1 - ((_image->getWidth() - widht) / _image->getWidth());
		float temp_y = 1 - ((_image->getHeight() - y) / _image->getHeight());
		float temp_height = 1 - ((_image->getHeight() - height) / _image->getHeight());
		
		_vertices[5] = temp_x;
		_vertices[6] = temp_y;
		_vertices[7 + 5] = temp_x;
		_vertices[7 + 6] = temp_y + temp_height;
		_vertices[7 * 2 + 5] = temp_x + temp_widht;
		_vertices[7 * 2 + 6] = temp_y + temp_height;
		_vertices[7 * 3 + 5] = temp_x + temp_widht;
		_vertices[7 * 3 + 6] = temp_y;


	}
	CMVector4<float> CMRectangle::GetTexturectangle()
	{
		return _textureRectangle;
	}
}