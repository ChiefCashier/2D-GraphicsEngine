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
#include <stdlib.h> 
#include <time.h>

CML::GraphicContext gcontext;
CML::RenderingContext rendContext;

int main()
{

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

	CML::CMRectangle r(0, 0, 400, 400);
	r.SetColor(0.0f, 1.0f, 0.0f, 1.0f);
	r.SetImage("sample.png");
	//CML::CMRectangle r2(200, 200, 400, 400);
	//r2.SetColor(0.0f, 1.0f, 0.0f, 1.0f);
	srand(time(NULL));
	while (true)
	{
		CML::CMSprite sprite = CML::CMSprite(0.0f, 0.0f, 0.0f, 0.0f, "sample.png");
		window.WindowMessageCheck();
		gcontext.Draw(r);
		gcontext.EndDraw();
		int x = (rand() % 10 * 50);
		int y = (rand() % 10 * 50);
		int z = (rand() % 10 + 1);
		r.SetWidth(z * 50);
		r.SetHeight(z * 50);
		r.SetX(x);
		r.SetY(y);
	}

	return 0;
}
