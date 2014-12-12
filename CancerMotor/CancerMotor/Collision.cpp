#include "Collision.h"

namespace CML
{ 
	bool Collision::CollisionRectangle(CMShape* r1, CMShape* r2)
	{
		if (r1->GetRotation() == 0 && r2->GetRotation() == 0)
		{
			if (r1->GetX() <= r2->GetX() && r2->GetX() <= (r1->GetX() + r1->GetWidth()) && r1->GetY() <= r2->GetY() && r2->GetY() <= (r1->GetY() + r1->GetHeight()))
				return true;
			else if (r1->GetX() <= r2->GetX() + r2->GetWidth() && (r2->GetX() + r2->GetWidth()) <= (r1->GetX() + r1->GetWidth()) && r1->GetY() <= r2->GetY() + r2->GetHeight() && (r2->GetY() + r2->GetHeight()) <= (r1->GetY() + r1->GetHeight()))
				return true;
			else
				return false;
		}
		else
		{
			if (r1->GetX() <= r2->GetX() <= r1->GetX() + r1->GetWidth() )
				if( r1->GetY() <= r2->GetY() <= r1->GetY() + r1->GetHeight() )
				{
					float x1 = r1->GetX() + std::cos(r1->GetRotation() * 3.141 / 180) * r1->GetWidth();
					float x2 = r1->GetX() + std::cos(r1->GetRotation() * 3.141 / 180 + 3.141 / 2) * r1->GetHeight();
					float y1 = r1->GetY() + std::sin(r1->GetRotation() * 3.141 / 180) * r1->GetWidth();
					float y2 = r1->GetY() + std::sin(r1->GetRotation() * 3.141 / 180 + 3.141 / 2) * r1->GetHeight();


					float xt1 = r2->GetX();
					float yt1 = r2->GetY();


					float xdifference1 = std::cos(r2->GetRotation() * 3.141 / 180)* r2->GetWidth();
					float xt2 = r2->GetX() + xdifference1;
					float ydifference1 = std::sin(r2->GetRotation() * 3.141 / 180) * r2->GetWidth();
					float yt2 = r2->GetY() + ydifference1;


					float xdifference2 = std::cos(r2->GetRotation() * 3.141 / 180 + 3.141 / 2)* r2->GetHeight();
					float xt3 = r2->GetX() + xdifference2;
					float ydifference2 = std::sin(r2->GetRotation() * 3.141 / 180 + 3.141 / 2) * r2->GetHeight();
					float yt3 = r2->GetY() + ydifference2;



					float xt4 = r2->GetX() + xdifference1 + xdifference2;
					float yt4 = r2->GetY() + ydifference1 + ydifference2;

					if (x1 + x2 + (xt1 - r1->GetX()) && y1 + y2 + (yt1 - r1->GetY()))
						return true;
					if (x1 + x2 + (xt2 - r1->GetX()) && y1 + y2 + (yt2 - r1->GetY()))
						return true;
					if (x1 + x2 + (xt3 - r1->GetX()) && y1 + y2 + (yt3 - r1->GetY()))
						return true;
					if (x1 + x2 + (xt4 - r1->GetX()) && y1 + y2 + (yt4 - r1->GetY()))
						return true;
				}
				else
					return false;
			else if(r1->GetX() <= r2->GetX() + r2->GetWidth() <= r1->GetX() + r1->GetWidth())
				if (r1->GetY() <= r2->GetY() + r2->GetHeight() <= r1->GetY() + r1->GetHeight())
				{
					float x1 = r1->GetX() + std::cos(r1->GetRotation() * 3.141 / 180) * r1->GetWidth();
					float x2 = r1->GetX() + std::cos(r1->GetRotation() * 3.141 / 180 + 3.141 / 2) * r1->GetHeight();
					float y1 = r1->GetY() + std::sin(r1->GetRotation() * 3.141 / 180) * r1->GetWidth();
					float y2 = r1->GetY() + std::sin(r1->GetRotation() * 3.141 / 180 + 3.141 / 2) * r1->GetHeight();


					float xt1 = r2->GetX();
					float yt1 = r2->GetY();

				
					float xdifference1 = std::cos(r2->GetRotation() * 3.141 / 180 )* r2->GetWidth();
					float xt2 = r2->GetX() + xdifference1;
					float ydifference1 = std::sin(r2->GetRotation() * 3.141 / 180) * r2->GetWidth();
					float yt2 = r2->GetY() + ydifference1;


					float xdifference2 = std::cos(r2->GetRotation() * 3.141 / 180 + 3.141 / 2)* r2->GetHeight();
					float xt3 = r2->GetX() + xdifference2;
					float ydifference2 = std::sin(r2->GetRotation() * 3.141 / 180 + 3.141 / 2) * r2->GetHeight();
					float yt3 = r2->GetY() + ydifference2;



					float xt4 = r2->GetX() + xdifference1 + xdifference2;
					float yt4 = r2->GetY() + ydifference1 + ydifference2;

					if (x1 + x2 + (xt1 - r1->GetX()) && y1 + y2 + (yt1 - r1->GetY()))
						return true;
					if (x1 + x2 + (xt2 - r1->GetX()) && y1 + y2 + (yt2 - r1->GetY()))
						return true;
					if (x1 + x2 + (xt3 - r1->GetX()) && y1 + y2 + (yt3 - r1->GetY()))
						return true;
					if (x1 + x2 + (xt4 - r1->GetX()) && y1 + y2 + (yt4 - r1->GetY()))
						return true;

				}
				else
					return false;
		}
	}
	bool Collision::CollisionCircle(CMCircle c1, CMCircle c2)
	{
		return true;
	}
	bool Collision::CollisionRectangleCircle(CMRectangle r, CMCircle c)
	{
		return true;
	}
}