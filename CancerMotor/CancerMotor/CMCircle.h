#pragma once
#include "CMShape.h"
class CMCircle :
	public CMShape
{
public:
	CMCircle(float _x, float _y, int sides);
	CMCircle();
	~CMCircle();

	void SetSides(int s);
	int GetSides();

private:
	int _sides;
};