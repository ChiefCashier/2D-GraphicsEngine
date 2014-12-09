#include "Entity.h"


Entity::Entity()
{
	_velocitySpeedDefault = 50.0f;
	_gravityAcceleration = 3.0f;
	_maxGravitySpeed = 40.0f;
	_currentVelocity = 0.0f;
	_flyingUp = false;
}


Entity::~Entity()
{
}
void Entity::Update(float deltaTime)
{
	//if in air or start jumped
	//std::cout << _flyingUp << std::endl;
	if (!HitsGround() || _jumping)
	{
		float newY = _shape.GetY();

			newY += _currentVelocity;
			_currentVelocity-= _gravityAcceleration;
		std::cout << newY << std::endl;
		_shape.SetY(newY);

		if (_shape.GetY()  < 50.0f)
		{
			_shape.SetY(100.0f);
			_currentVelocity = 0.0f;
			_jumping = false;
		}
		


	}
	

}
bool Entity::HitsGround()
{
	if (_shape.GetY()-_shape.GetOrigon().getY() <= 0.0f)
	{
		return true;
	}
	return false;
}
void Entity::Jump()
{
	_jumping = true;
	_flyingUp = true;
	_currentVelocity = _velocitySpeedDefault;
}