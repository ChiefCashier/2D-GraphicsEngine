#include "Enemy.h"


Enemy::Enemy(float x, float y)
{
	shape = CML::CMRectangle(x, y, 150, 150);
	shape.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	shape.SetColor(1.0f, 0.0f, 0.0f, 0.0f);
	shape.SetOrigon(-75, -75);
}

CML::CMShape *Enemy::returnShape()
{
	return &shape;
}

void Enemy::EnemyMove(float px, float py)
{
	if (shape.GetY() - shape.GetHeight() / 2 > 0 )
		shape.SetY(shape.GetY() - 5);

	//shape.SetX(shape.GetY() - px);


}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
