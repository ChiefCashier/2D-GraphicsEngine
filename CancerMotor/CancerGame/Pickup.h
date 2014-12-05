#pragma once
#include <CMWindow.h>
#include <CMCircle.h>
#include <CMRectangle.h>
#include <CMVector2.h>

class Pickup
{
public:
	Pickup(float x, float y);

	Pickup();
	~Pickup();
	CML::CMShape *returnShape();
private:
	CML::CMRectangle shape;
	CML::CMVector2<float> speed;
	CML::CMVector2<float> position;
};

