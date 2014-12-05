#pragma once

#include "CMWindow.h"
#include "CMRectangle.h"
#include "CMCircle.h"
#include "CMInput.h"
class Player
{
public:
	Player();
	~Player();

	enum Shapes {PLAYER, CURSOR};

	void playerInputs(float mx, float my);

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

private:
	CML::CMRectangle player;
	CML::CMShape cursor;
};