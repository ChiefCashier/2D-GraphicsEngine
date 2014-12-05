#pragma once
#include <CMRectangle.h>

class Entity
{
public:
	Entity();
	~Entity();
	void Update(float deltaTime);
protected:
	CML::CMRectangle _shape;
	float _gravityAcceleration;
	float _gravitySpeed;
	float _gravitySpeedDefault;
	float _maxGravitySpeed;
	bool _flyingUp;
	bool HitsGround();
	bool _jumping;
	void Jump();
};

