#include "CMCircle.h"

CMCircle::CMCircle(float _x, float _y, int sides) : CMShape(_x, _y)
{
	_sides = sides;
}
CMCircle::CMCircle() : CMShape()
{
}
CMCircle::~CMCircle()
{
}

void CMCircle::SetSides(int s)
{
	_sides = s;
}

int CMCircle::GetSides()
{
	return _sides;
}