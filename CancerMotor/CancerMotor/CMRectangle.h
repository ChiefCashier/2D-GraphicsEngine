#pragma once
#include "CMShape.h"
namespace CML
{
	class CMRectangle : public CMShape
	{
	public:

		CMRectangle(float _x, float _y, float width, float height);
		CMRectangle();
		~CMRectangle();

		void SetX(float x);
		void SetY(float y);

		void SetTextureRectangle(float x, float y, float height, float widht);
		CMVector4<float> GetTexturectangle();

	private:

		
	};
}