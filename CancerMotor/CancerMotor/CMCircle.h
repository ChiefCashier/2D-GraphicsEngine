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

		void SetColor(float r, float g, float b, float a);

	private:

		float _radius;
		int _sides;

	};
}