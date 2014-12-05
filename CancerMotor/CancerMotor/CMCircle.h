#pragma once
#include "CMShape.h"
namespace CML
{
	class CMCircle :
		public CMShape
	{
	public:

		CMCircle(float _x, float _y, float _radius, int sides);
		CMCircle();
		~CMCircle();

		void SetSides(int s);
		int GetSides();

		void SetRadius(int r);
		int GetRadius();

		void SetTextureRectangle(float x, float y, float widht, float height);
		CMVector4<float> GetTexturectangle();

	private:

		float _radius;
		int _sides;

	};
}