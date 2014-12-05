#include "Entity.h"


Entity::Entity()
{
	_gravitySpeed = 0.0f;
	_gravitySpeedDefault = 20.0f;
	_gravityAcceleration = 3.0f;
	_maxGravitySpeed = 40.0f;
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
		if (_flyingUp)
		{
			if (_gravitySpeed >= _maxGravitySpeed)
				_flyingUp = false;
			else
			{
				newY += _gravitySpeed;
				_gravitySpeed += _gravityAcceleration;
			}
		}
		else //flying down
		{
			newY += _gravitySpeed;
			_gravitySpeed -= _gravityAcceleration;
		std::cout << newY << std::endl;
		}

		if (_shape.GetY()  < 50.0f)
		{
			_shape.SetY(50.0f);
			_jumping = false;
		}
		
		_shape.SetY(newY);

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
	_gravitySpeed = _gravitySpeedDefault;
}