#pragma once

#include "CMWindow.h"
#include "CMRectangle.h"
#include "CMCircle.h"
#include "CMInput.h"
#include "Entity.h"
class Player
	: public Entity
{
public:
	Player();
	~Player();

	enum Shapes {PLAYER, CURSOR};

	void playerInputs(float mx, float my);
	CML::CMRectangle *GetCursor();
	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	float GetWidth();
	float GetHeight();

	void SetWidth(float x);
	void SetHeight(float y);

	void SetRotation(float a);
	float GetRotation();

	CML::CMShape *returnPaska(Shapes s);
	void doPickupEffect();
private:
	CML::CMRectangle player;
	CML::CMRectangle cursor;

	float _pickupSizeIncreaseAmount; //how much size is increased overall
	CML::CMVector2<float> _pickupTargetSize; // what is target size (when on effect current size + _pickupSizeIncreaseAmount)
	bool _isOnPickupEffect; //is Size being increased?
	float _pickupFrameIncreaseAmount; // how much size is being increased per frame (if its smaller than _pickupSizeIncreaseAmount)
};