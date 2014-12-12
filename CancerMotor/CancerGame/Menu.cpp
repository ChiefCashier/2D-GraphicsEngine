#include "Menu.h"


Menu::Menu()
{
	menu = CML::CMRectangle(500, 500, 500, 500);
	menu.SetImage(CML::ResourceManager::createResource<CML::CMImage>("Menu.png"));
	menu.SetRotation(0.0f);
	menu.SetSize(CML::CMVector2<float>(-1.0f, 1.0f));
	menu.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	menu.SetOrigon(250, 250);
}


Menu::~Menu()
{
}

CML::CMShape *Menu::returnShape()
{
	return &menu;
}

float Menu::GetX()
{
	return menu.GetX();
}

float Menu::GetY()
{
	return menu.GetY();
}

void Menu::SetX(float x)
{
	menu.SetX(x);
}

void Menu::SetY(float y)
{
	menu.SetY(y);
}

float Menu::GetWidth()
{
	return menu.GetWidth();
}

float Menu::GetHeight()
{
	return menu.GetHeight();
}

void Menu::SetWidth(float x)
{
	menu.SetWidth(x);
}

void Menu::SetHeight(float y)
{
	menu.SetHeight(y);
}

void Menu::SetRotation(float a)
{
	menu.SetRotation(a);
}

float Menu::GetRotation()
{
	return menu.GetRotation();
}