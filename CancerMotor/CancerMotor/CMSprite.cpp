#include "CMSprite.h"

namespace CML
{
	CMSprite::CMSprite()
	{
		_xPosition = 0.0f;
		_yPosition = 0.0f;
		_widht = 800.0f;
		_height = 600.0f;

		_colorRed = { 0.0f }, _colorGreen = { 0.0f }, _colorBlue = { 0.0f };
		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_image = CML::CMImage::CMImage("sample.png");
	}
	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height, char* hattu)
	{
		_xPosition = xPosition;
		_yPosition = yPosition;
		_widht = widht;
		_height = height;

		_colorRed = { 0.0f }, _colorGreen = { 0.0f }, _colorBlue = { 0.0f };
		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_image = CML::CMImage::CMImage(hattu);
	}

	CMSprite::~CMSprite()
	{ 
	}

	float CMSprite::GetX()
	{
		return _xPosition;
	}

	void CMSprite::SetX()
	{
	
	}

	float CMSprite::GetY()
	{
		return _yPosition;
	}

	void CMSprite::SetY()
	{
		
	}

	float CMSprite::GetWidht()
	{
		return _widht;
	}

	void CMSprite::SetWidht()
	{
	
	}

	float CMSprite::GetHeight()
	{
		return _height;
	}

	void CMSprite::SetHeight()
	{
	
	}

	float CMSprite::GetColorRed()
	{
		return _colorRed;
	}

	void CMSprite::SetColorRed()
	{
	
	}

	float CMSprite::GetColorGreen()
	{
		return _colorGreen;
	}

	void CMSprite::SetColorGreen()
	{
	
	}

	float CMSprite::GetColorBlue()
	{
		return _colorBlue;
	}

	void CMSprite::SetColorBlue()
	{
	
	}

	CMImage CMSprite::GetImage()
	{
		return _image;
	}

	void CMSprite::SetImage()
	{
	
	}
	float CMSprite::GetTexturePositionX()
	{
		return _texturePositionX;
	}

	void CMSprite::SetTexturePositionX()
	{
	
	}

	float CMSprite::GetTexturePositionY()
	{
		return _texturePositionY;
	}

	void CMSprite::SetTexturePositionY()
	{
	
	}

	float CMSprite::GetTextureHeight()
	{
		return _image.getHeight();
	}

	void CMSprite::SetTextureHeight()
	{
	
	}

	float CMSprite::GetTextureWidht()
	{
		return _image.getWidth();
	}

	void CMSprite::SetTextureWidht()
	{
	
	}
}