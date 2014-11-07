#include "CMSprite.h"

namespace CML
{
	CMSprite::CMSprite()
	{
		_x = 0.0f;
		_y = 0.0f;
		_widht = 200.0f;
		_height = 300.0f;

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_image = nullptr;
	}

	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height)
	{
		_x = xPosition;
		_y = yPosition;
		_widht = widht;
		_height = height;

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_image = nullptr;
		_textureHeight = 0;
		_textureWidht = 0;
	}

	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height, char* imageLocation)
	{
		_x = xPosition;
		_y = yPosition;
		_widht = widht;
		_height = height;

		_image = CML::CMImage::CMImage(imageLocation);

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_textureHeight = _image.getHeight();
		_textureWidht = _image.getWidth();

	}
	CMSprite::CMSprite(float xPosition, float yPosition, float widht, float height, CMImage image)
	{
		_x = xPosition;
		_y = yPosition;
		_widht = widht;
		_height = height;

		_image = image;

		_texturePositionX = { 0.0f }, _texturePositionY = { 0.0f };
		_textureHeight = _image.getHeight();
		_textureWidht = _image.getWidth();

	}

	CMSprite::~CMSprite()
	{ 

	}


	float CMSprite::GetWidht()
	{
		return _widht;
	}

	void CMSprite::SetWidht(float widht)
	{
		_widht = widht;
	}

	float CMSprite::GetHeight()
	{
		return _height;
	}

	void CMSprite::SetHeight(float height)
	{
		_height = height;
	}

	CMImage CMSprite::GetImage()
	{
		return _image;
	}

	void CMSprite::SetImage(char* imageLocation)
	{
		_image = CML::CMImage::CMImage(imageLocation);
	}
	float CMSprite::GetTexturePositionX()
	{
		return _texturePositionX;
	}

	void CMSprite::SetTexturePositionX(float texPosX)
	{
		_texturePositionX = texPosX;
	}

	float CMSprite::GetTexturePositionY()
	{
		return _texturePositionY;
	}

	void CMSprite::SetTexturePositionY(float texPosY)
	{
		_texturePositionY = texPosY;
	}

	float CMSprite::GetTextureHeight()
	{
		return _textureHeight;
	}

	void CMSprite::SetTextureHeight(float texHeight)
	{
		_textureHeight = texHeight;
	}

	float CMSprite::GetTextureWidht()
	{
		return _textureWidht;
	}

	void CMSprite::SetTextureWidht(float texWidht)
	{
		_textureWidht = texWidht;
	}
}