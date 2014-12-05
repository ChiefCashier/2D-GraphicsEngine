#include "Menu.h"


Menu::Menu()
{
	menu = CML::CMRectangle(350, 350, 500, 500);
	menu.SetImage(CML::ResourceManager::createResource<CML::CMImage>("noppia.png"));
	menu.SetRotation(0.0f);
	menu.SetSize(1.0f);
	menu.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	menu.SetOrigon(-100, -100);
}


Menu::~Menu()
{
}

CML::CMShape *Menu::returnShape()
{
	return &menu;
}