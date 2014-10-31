#pragma once
#include "CMImage.h"
#include "CMShape.h"
#include <string>

namespace CML
{
	class CMSprite : CMShape
	{
	public:

		CMSprite();
		CMSprite(float, float, float, float);
		CMSprite(float, float, float, float, char*);
		CMSprite(float, float, float, float, CMImage);
		~CMSprite();

		float GetWidht();
		void SetWidht(float);

		float GetHeight();
		void SetHeight(float);

		CMImage GetImage();
		void SetImage(char*);

		float GetTexturePositionX();
		void SetTexturePositionX(float);

		float GetTexturePositionY();
		void SetTexturePositionY(float);

		float GetTextureWidht();
		void SetTextureWidht(float);

		float GetTextureHeight();
		void SetTextureHeight(float);


	private:
		float _height, _widht;
		float _texturePositionX, _texturePositionY;
		float _textureWidht, _textureHeight;
		CMImage _image;

	};
}