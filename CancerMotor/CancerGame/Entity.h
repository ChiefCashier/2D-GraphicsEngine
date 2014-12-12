#pragma once
#include <CMRectangle.h>

class Entity
{
public:
	Entity();
	~Entity();
	void Update(float deltaTime);
	bool _jumping;
	void Jump();
protected:
	CML::CMRectangle _shape;
	float _gravityAcceleration;
	float _velocitySpeedDefault;
	float _maxGravitySpeed;
	float _currentVelocity;
	bool _flyingUp;
	bool HitsGround();

};

