#pragma once
#include "CMRectangle.h"
#include "ResourceManager.h"

class Player
{
public:
	Player();
	~Player();

	void playerInputs();

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	float GetWidth();
	float GetHeight();

	void SetSize(float x);

	void SetRotation(float a);
	float GetRotation();

	CML::CMRectangle *returnPaska();

private:
	CML::CMRectangle player;
};