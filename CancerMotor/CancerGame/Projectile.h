#pragma once
#include "CMWindow.h"
#include "CMCircle.h"
#include "CMRectangle.h"
#include "CMVector2.h"
class Projectile
{
public:
	Projectile(float mx, float my, float px, float py);
	void MoveProjectiles();
	void doThings();
	bool Collision(float x, float y);

	CML::CMVector2<float> GetSpeed();
	
	Projectile();
	~Projectile();
	CML::CMShape *returnPaska();
private:
	CML::CMRectangle bullet;
	CML::CMVector2<float> speed;
	CML::CMVector2<float> position;
};

