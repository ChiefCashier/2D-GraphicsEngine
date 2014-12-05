#pragma once

#include "CMWindow.h"
#include "CMShape.h"
#include "CMRectangle.h"
#include "CMInput.h"

class Menu
{
public:
	enum MenuResult { Nothing, Play, Exit};

	Menu();
	~Menu();

	CML::CMShape *returnShape();

private:
	CML::CMRectangle menu;
};

