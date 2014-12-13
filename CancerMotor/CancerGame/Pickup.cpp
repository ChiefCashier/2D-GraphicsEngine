#include "Pickup.h"
#include <ResourceManager.h>


Pickup::Pickup(float x, float y) : Entity()
{
	_shape = CML::CMRectangle(x, y, 100.0f, 100.0f);
	_shape.SetOrigon(50.0f, 50.0f);
	_shape.SetRotation(0.0f);
	_shape.SetSize(CML::CMVector2<float>(1.0f,1.0f));
	_shape.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	_shape.SetImage(CML::ResourceManager::createResource<CML::CMImage>("pilleri.psd"));

}


Pickup::~Pickup()
{
	
}