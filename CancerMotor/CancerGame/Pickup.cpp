#include "Pickup.h"


Pickup::Pickup(float x, float y)
{
	shape = CML::CMRectangle(x, y, 150, 150);
	shape.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	shape.SetColor(1.0f, 0.0f, 0.0f, 0.0f);
	shape.SetOrigon(-75, -75);
}


CML::CMShape *Pickup::returnShape()
{
	return &shape;
}


Pickup::Pickup()
{
}


Pickup::~Pickup()
{
}
