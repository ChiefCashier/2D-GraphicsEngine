#pragma once
#include <CMWindow.h>
#include <CMRectangle.h>
#include <CMVector2.h>
#include "Entity.h"
class Enemy
	:public Entity
{
public:
	Enemy(float x, float y);
	void Update(float playerX);

	Enemy();
	~Enemy();
	CML::CMShape *returnShape();
	float _jumpDelayMax;
	float _jumpDelayMin;
	float _currentTime;
};

