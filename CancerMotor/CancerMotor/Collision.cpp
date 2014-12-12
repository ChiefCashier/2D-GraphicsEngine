#include "Collision.h"

namespace CML
{ 
	bool Collision::CollisionRectangle(CMShape* r1, CMShape* r2)
	{
		if (r1->GetRotation() == 0 && r2->GetRotation() == 0)
		{
			if (r1->GetX() - (r1->GetOrigon().getX()*r1->GetSize().getX()) <= r2->GetX() - (r2->GetOrigon().getX()*r2->GetSize().getX()))
			{
				if (r2->GetX() - (r2->GetOrigon().getX()*r2->GetSize().getX()) <= (r1->GetX() - r1->GetOrigon().getX() + r1->GetWidth()))
				{
					if (r1->GetY() - (r1->GetOrigon().getY()*r1->GetSize().getY()) <= r2->GetY() - (r2->GetOrigon().getY()*r2->GetSize().getY()))
					{
						if (r2->GetY() - (r2->GetOrigon().getY()*r2->GetSize().getY()) <= (r1->GetY() - (r1->GetOrigon().getY()*r1->GetSize().getY()) + r1->GetHeight()))
						{
							return true;
						}
					}
				}
			}
			else if (r1->GetX() - (r1->GetOrigon().getX()*r1->GetSize().getX()) <= r2->GetX() - (r2->GetOrigon().getX()*r2->GetSize().getX()) + r2->GetWidth())
			{
				if ((r2->GetX() - (r2->GetOrigon().getX()*r2->GetSize().getX()) + r2->GetWidth()) <= (r1->GetX() - r1->GetOrigon().getX() + r1->GetWidth()))
				{
					if (r1->GetY() - (r1->GetOrigon().getY()*r1->GetSize().getY()) <= r2->GetY() - (r2->GetOrigon().getY()*r2->GetSize().getY()) + r2->GetHeight())
					{
						if ((r2->GetY() - (r2->GetOrigon().getY()*r2->GetSize().getY()) + r2->GetHeight()) <= (r1->GetY() - (r1->GetOrigon().getY()*r1->GetSize().getY()) + r1->GetHeight()))
						{
							return true;
						}
					}
				}
			}
			else
				return false; 
		}
		else 
		{
			if (r1->GetX() <= r2->GetX() <= r1->GetX() + r1->GetWidth() )
				if( r1->GetY() <= r2->GetY() <= r1->GetY() + r1->GetHeight() )
				{
					
					
				}
				else
					return false;
			else if(r1->GetX() <= r2->GetX() + r2->GetWidth() <= r1->GetX() + r1->GetWidth())
				if (r1->GetY() <= r2->GetY() + r2->GetHeight() <= r1->GetY() + r1->GetHeight())
				{
					

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