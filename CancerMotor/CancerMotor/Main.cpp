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
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
CML::GraphicContext gcontext;
CML::RenderingContext rendContext;

int main()
{

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
	gcontext.Initialize(&rendContext);
	srand(time(NULL));
	std::vector<CML::CMRectangle*> lista;
	
	for (int i = 0; i < 700; i++)
	{
		CML::CMRectangle *a = new CML::CMRectangle((rand() % 825 ), (rand() % 750 ), 50, 50);
		a->SetColor(1.0f, 1.0f, 1.0f, 0.0f);
		a->SetRotation(0.0f);
		a->SetSize(1.0f);
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
				
			//x += 0.1;
			y = glm::cos(i) * 5;
			//int z = (rand() % 2 + 1);
			//lista.at(j)->SetSize(z * 0.5f);
			lista.at(j)->SetY(y + lista.at(j)->GetY());
			lista.at(j)->SetX(lista.at(j)->GetX() - x);
			i += 0.01;
			if (i > 360)
				i = 0;
			if (lista.at(j)->GetX() <= -40)
				lista.at(j)->SetX(800);
		}
		//std::cout << CML::CMInput::getMouseX(asd);
		//std::cout << "   ";
		//std::cout << CML::CMInput::getMouseY(asd);
		//std::cout << std::endl;

		gcontext.EndDraw();
		
		if(CML::CMInput::isKeyPressed(CML::CMInput::Escape))
			break;
		

	}



	//delete(asd);
	return 0;
}
