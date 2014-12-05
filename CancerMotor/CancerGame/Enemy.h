#pragma once
#include <CMWindow.h>
#include <CMRectangle.h>
#include <CMVector2.h>

class Enemy
{
public:
	Enemy(float x, float y);
	void EnemyMove(float px, float py);

	Enemy();
	~Enemy();
	CML::CMShape *returnShape();
private:
	CML::CMRectangle shape;
};

