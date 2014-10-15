#pragma once
#include "CMImage.h"
#include <string>

namespace CML
{
	class CMSprite
	{
	public:

		CMSprite();
		CMSprite(float, float, float, float, char*);
		~CMSprite();

		float GetX();
		void SetX();

		float GetY();
		void SetY();

		float GetWidht();
		void SetWidht();

		float GetHeight();
		void SetHeight();

		float GetColorRed();
		void SetColorRed();

		float GetColorGreen();
		void SetColorGreen();

		float GetColorBlue();
		void SetColorBlue();

		CMImage GetImage();
		void SetImage();

		float GetTexturePositionX();
		void SetTexturePositionX();

		float GetTexturePositionY();
		void SetTexturePositionY();

		float GetTextureWidht();
		void SetTextureWidht();

		float GetTextureHeight();
		void SetTextureHeight();


	private:

		float _xPosition, _yPosition, _widht, _height;// rect would be better
		float _colorRed, _colorGreen, _colorBlue;
		float _texturePositionX, _texturePositionY;
		float _textureWidht, _textureHeight;
		CMImage _image;

	};
}