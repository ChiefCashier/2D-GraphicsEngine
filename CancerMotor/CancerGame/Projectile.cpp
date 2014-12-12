#include "Projectile.h"
#include <GraphicContext.h>

Projectile::Projectile(float mx, float my, float px, float py)
{
	bullet = CML::CMRectangle(mx, my, 50, 50);
	bullet.SetImage(CML::ResourceManager::createResource<CML::CMImage>("highresbullet.png"));
	bullet.SetColor(1.0f, 0.0f, 0.0f, 0.0f);
	bullet.SetOrigon(75, 75);
	bullet.SetSize(CML::CMVector2<float>(0.05f, 0.05f));

	float Dx = px - mx;
	float Dy = py - my;

	float DLen = sqrt(Dx*Dx + Dy*Dy);
	Dx /= DLen;
	Dy /= DLen;

	bullet.SetX(px + Dx*-150);
	bullet.SetY(py + Dy*-150);

	speed.setX(((Dx)*-20));
	speed.setY(((Dy)*-20));

}

void Projectile::MoveProjectiles()
{
	bullet.SetX(bullet.GetX() + speed.getX());
	bullet.SetY(bullet.GetY() + speed.getY());

	//bullet.SetRotation(bullet.GetRotation() + 10);
	bullet.SetColor((rand() % 100)/100.0f , (rand() % 100)/100.0f, (rand() % 100)/100.0f, 0.0f);
}

bool Projectile::Collision(float x, float y)
{
	if (bullet.GetX() < x + 75
		&& bullet.GetX() > x - 75
		&& bullet.GetY() < y + 75
		&& bullet.GetY() > y - 90)
		return true;
	else
		return false;
}

void Projectile::doThings()
{

}


CML::CMVector2<float> Projectile::GetSpeed()
{
	return speed;
}


CML::CMShape *Projectile::returnPaska()
{
	return &bullet;
}

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
	CML::GraphicContext::RemoveDrawable(&bullet);
}
