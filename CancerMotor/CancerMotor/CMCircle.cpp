#include "CMCircle.h"
namespace CML
{
	CMCircle::CMCircle(float _x, float _y, float radius, int sides) : CMShape(_x, _y)
	{
		_radius = radius;
		_sides = sides;




		for (int i = 0; i < sides; i++)
			_indices.push_back((GLuint)i);

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

	void CMCircle::SetRadius(int r)
	{
		_radius = r;
	}

	int CMCircle::GetRadius()
	{
		return _radius;
	}
}