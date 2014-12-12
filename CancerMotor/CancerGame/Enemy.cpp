#include "Enemy.h"
#include <math.h>


Enemy::Enemy(float x, float y) : Entity()
{
	_shape = CML::CMRectangle(x, y, 150, 150);
	_shape.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	_shape.SetColor(1.0f, 0.0f, 0.0f, 0.0f);
	_shape.SetOrigon(75, 75);
	_jumpDelayMax = 4.0f;
	_jumpDelayMin = 1.0f;
	_currentTime = _currentTime = (rand() % (int)_jumpDelayMax) + _jumpDelayMin;
}

CML::CMShape *Enemy::returnShape()
{
	return &_shape;
}

void Enemy::Update(float playerX)
{
	Entity::Update(0.0f);
	if (_currentTime <= 0)
	{
		Jump();
		_currentTime = (rand() % (int)_jumpDelayMax) + _jumpDelayMin;
	}
	else
	{
		_currentTime -= 0.016;
	}
	float width = std::abs(_shape.GetWidth());
	if (playerX < _shape.GetX())
	{
		_shape.SetX(_shape.GetX() - 1);
		_shape.SetTextureRectangle(0.0f, 0.0f, -static_cast<float>(_shape.GetImage()->getWidth()), _shape.GetImage()->getHeight());
	}
	else if (playerX > _shape.GetX())
	{
		_shape.SetX(_shape.GetX() + 1);
		_shape.SetTextureRectangle(0.0f, 0.0f, static_cast<float>(_shape.GetImage()->getWidth()), _shape.GetImage()->getHeight());
	}
	
	//shape.SetX(shape.GetY() - px);
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
