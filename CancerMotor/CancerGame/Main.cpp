#include "CMWindow.h"
#include "glew.h"
#include "ResourceManager.h"
#include "glm\glm.hpp"
#include "CMSprite.h"
#include <string>
#include <iostream>
#include "RenderingContext.h"
#include "GraphicContext.h"
#include "CMShape.h"
#include "CMRectangle.h"
#include "CMInput.h"
#include "CMCircle.h"
#include <stdlib.h> 
#include <time.h>
#include "CMVector2.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include "Game.h"


int main()
{
	Game g;

	/*glewInit();
	CML::CMWindow window(0, L"asd", 800, 800);
	window.ShowCMWindow();
	rContext = CML::RenderingContext(&window);
	gcontext.Initialize(&rContext);


	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);


	srand(time(NULL));
	std::vector<CML::CMCircle*> lista;

	for (int i = 0; i < 50; i++)
	{
	CML::CMCircle *a = new CML::CMCircle(rand()%850, rand()%750, 50, (360 / 3));
	a->SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	a->SetRotation(0.0f);
	a->SetSize(1.0f);
	if (i % 2 == 0)
	a->SetImage(CML::ResourceManager::createResource<CML::CMImage>("noppia.png"));
	else
	a->SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));

	lista.push_back(a);
	}


	float i = 0;
	int x = 2;
	int y;

	while (true)
	{

	window.WindowMessageCheck();

	for (int j = 0; j < lista.size(); j++)
	{
	gcontext.Draw(lista.at(j));

	y = glm::cos(i) * 7;

	lista.at(j)->SetY(y + lista.at(j)->GetY());
	lista.at(j)->SetX(lista.at(j)->GetX() - x);
	i += 0.1;
	if (i > 360)
	i = 0;
	if (lista.at(j)->GetX() <= -40)
	lista.at(j)->SetX(800);
	}

	gcontext.EndDraw();

	if(CML::CMInput::isKeyPressed(CML::CMInput::Escape))
	break;


	}*/


	return 0;
}
