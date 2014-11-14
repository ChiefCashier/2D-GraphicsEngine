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
#include <stdlib.h> 
#include <time.h>
#include "CMVector2.h"
CML::GraphicContext gcontext;
CML::RenderingContext rendContext;

int main()
{
	//CML::CMVector2<int> vec = CML::CMVector2<int>(5, 2);
	//CML::CMVector2<int> vec2 = CML::CMVector2<int>(5, 2);
	////vec = vec + vec2;
	//vec -= vec2;
	////if (vec == vec2)
	//std::cout << vec << std::endl;
	//system("PAUSE");


	CML::CMWindow window(0, L"asd", 800, 800);
	window.ShowCMWindow();
	rendContext = CML::RenderingContext(&window);
	rendContext.createVertexShader();
	rendContext.createFragmentShader();
	gcontext = CML::GraphicContext();


	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	HWND asd = window.CMWindowHandle();
	gcontext.BeginDraw(&rendContext);

	std::vector<CML::CMRectangle*> lista;
	for (int i = 0; i < 1; i++)
	{
		CML::CMRectangle *a = new CML::CMRectangle(0, 0, 400, 400);
		
		a->SetColor(0.0f, 1.0f, 0.0f, 1.0f);
		a->SetImage("sample.png");
		lista.push_back(a);
	}

	srand(time(NULL));
	
	while (true)
	{		
		window.WindowMessageCheck();
		for (int j = 0; j < lista.size(); j++)
		{
			gcontext.Draw(*lista.at(j));
			int x = (rand() % 10 * 50);
			int y = (rand() % 10 * 50);
			int z = (rand() % 10 + 1);
			lista.at(j)->SetWidth(z * 50);
			lista.at(j)->SetHeight(z * 50);
			lista.at(j)->SetX(x);
			lista.at(j)->SetY(y);
		}
		std::cout << CML::CMInput::getMouseX(asd);
		std::cout << "   ";
		std::cout << CML::CMInput::getMouseY(asd);
		std::cout << std::endl;

		gcontext.EndDraw();
		
		CML::CMInput::isKeyPressed(CML::CMInput::Escape);
		

	}



	delete(asd);
	return 0;
}
