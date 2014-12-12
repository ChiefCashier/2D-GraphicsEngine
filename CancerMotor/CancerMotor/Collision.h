#pragma once
#include "CMRectangle.h"
#include "CMCircle.h"
#include "CMShape.h"
#include <math.h>
namespace CML
{
	class Collision
	{
	public:

		static bool CollisionRectangle(CMShape* r1, CMShape* r2);
		static bool CollisionCircle(CMCircle c1, CMCircle c2);
		static bool CollisionRectangleCircle(CMRectangle r, CMCircle c);
	};
}
