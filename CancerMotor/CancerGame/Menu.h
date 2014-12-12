#pragma once

#include "CMWindow.h"
#include "CMShape.h"
#include "CMRectangle.h"
#include "CMInput.h"

class Menu
{
public:

	Menu();
	~Menu();

	CML::CMShape *returnShape();

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

private:
	CML::CMRectangle menu;
};

