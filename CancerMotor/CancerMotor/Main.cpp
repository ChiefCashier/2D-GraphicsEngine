#include "CMWindow.h"
#include "glew.h"
#include "ResourceManager.h"
#include "glm\glm.hpp"
#include "CMSprite.h"
#include <string>
#include <iostream>
#include "RenderingContext.h"
#include "GraphicContext.h"

CML::GraphicContext gcontext;
	CML::RenderingContext rendContext;
void Render(HWND asd);
int main()
{
	// kaikki on paskaa
	




	CML::CMWindow window(0, L"asd", 800, 600);
	window.ShowCMWindow();
	rendContext = CML::RenderingContext(&window);
	rendContext.createVertexShader();
	rendContext.createFragmentShader();
	gcontext = CML::GraphicContext();





	//Here lies componets for rendering

















	//_texture = glGetUniformLocation(_program, "myTexture"); 
	//assert(_texture >= 0);







	//Buffers

	/*
	if(puffer)assert puffer

	puffer.koko / 7 = vertexcount

	glBufferData(GL_ARRAY_BUFFER, 7 * vertexcountsizeof(GLfloat), VERTEX_DATA, GL_STATIC_DRAW);

	else

	teejotainjuttuja()
	*/
	//	int _windowHeight = 600;
		//int _windowWidht = 800;

	//Data buhveli, in order: 2x position, 3x colour, 2x texture coordinates
	GLfloat _vertexBufferInput[] = {

		//clean and simple
		/*

		1		3



		2		4

		*/

		//1st vertex
		200.0f, 200.0f,
		//1st color
		0.0f, 0.0f, 0.0f,
		//1st tex coords
		0.0f, -1.0f,

		//2nd vertex
		200.0f, 700.0f,
		//2nd color
		0.0f, 0.0f, 0.0f,
		//2nd tex coords
		0.0f, 0.0f,

		//3rd
		700.0f, 700.0f,
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f,
		/*QUAD CODE
		//4rd vertex
		1.0f, 0.0f,
		//3rd color
		0.0f, 0.0f, 1.0f,
		//3rd tex coords
		1.0f, 0.0f
		*/

		//2nd vertex
		700.0f, 200.0f,
		//2nd color
		0.0f, 0.0f, 0.0f,
		//2nd tex coords
		1.0f, -1.0f

		//not so clean and simple...
		

		/*
		((sprite.GetX() / _windowWidht) * 2) - 1, ((sprite.GetY() / _windowHeight) * 2) - 1,					// here sprite positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		(sprite.GetTexturePositionX() / _windowWidht), (sprite.GetTexturePositionY() / _windowHeight),			// here sprite texture positions are transformed to opengl format 

		((sprite.GetX() / _windowWidht) * 2) - 1, 600.0f/*((sprite.GetHeight() / _windowHeight) * 2) - 1,				// here sprite positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		(sprite.GetTexturePositionX() / _windowWidht), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),				// here sprite texture positions are transformed to opengl format 

		600.0f/*((sprite.GetWidht() / _windowWidht) * 2) - 1, 600.0f /*((sprite.GetHeight() / _windowHeight) * 2) - 1,			// here sprite positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		sprite.GetTextureWidht() / sprite.GetImage().getWidth(), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),		// here sprite positions are transformed to opengl format 

		600.0f/*((sprite.GetWidht() / _windowWidht) * 2) - 1, ((sprite.GetY() / _windowHeight) * 2) - 1,				// here sprite texture positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		sprite.GetTextureWidht() / sprite.GetImage().getWidth(), (sprite.GetTexturePositionY() / _windowHeight),				// here sprite positions are transformed to opengl format 
		*/
		//0.0f, 400.0f,
		//sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//(sprite.GetTexturePositionX() / _windowWidht), (sprite.GetTexturePositionY() / _windowHeight),

		//400.0f,400.0f,
		//sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//(sprite.GetTexturePositionX() / _windowWidht), (sprite.GetTexturePositionY() / _windowHeight),

		//0.0f,0.0f,

		//sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//(sprite.GetTexturePositionX() / _windowWidht), (sprite.GetTexturePositionY() / _windowHeight)
		//



		//((sprite2.GetX() / _windowWidht) * 2) - 1, ((sprite2.GetY() / _windowHeight) * 2) - 1,					// here sprite positions are transformed to opengl format 
		//sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//(sprite2.GetTexturePositionX() / _windowWidht), (sprite2.GetTexturePositionY() / _windowHeight),		// here sprite texture positions are transformed to opengl format 

		//((sprite2.GetX() / _windowWidht) * 2) - 1, ((sprite2.GetHeight() / _windowHeight) * 2) - 1,				// here sprite positions are transformed to opengl format 
		//sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//(sprite2.GetTexturePositionX() / _windowWidht), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),			// here sprite texture positions are transformed to opengl format 

		//((sprite2.GetWidht() / _windowWidht) * 2) - 1, ((sprite2.GetHeight() / _windowHeight) * 2) - 1,			// here sprite positions are transformed to opengl format 
		//sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//sprite.GetTextureWidht() / sprite.GetImage().getWidth(), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),		// here sprite texture positions are transformed to opengl format 

		//((sprite2.GetWidht() / _windowWidht) * 2) - 1, ((sprite2.GetY() / _windowHeight) * 2) - 1,				// here sprite positions are transformed to opengl format 
		//sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		//sprite.GetTextureWidht() / sprite.GetImage().getWidth(), (sprite2.GetTexturePositionY() / _windowHeight)				// here sprite texture positions are transformed to opengl format 

	};













	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	HWND asd = window.CMWindowHandle();
	gcontext.BeginDraw(&rendContext);
	while (true)
	{
		Render(asd);
		window.WindowMessageCheck();
	
	}
		
	//poista kun debugger luokka valmis
	//system("PAUSE");
	return 0;
}
void Render(HWND windowh)
{

	wglMakeCurrent(GetDC(windowh), rendContext.getRenderingContext());
	CML::Rectangle r;
	r.SetX(400.0f);
	r.SetY(300.0f);
	r.SetHeight(100);
	r.SetWidth(100);
	r.SetColor(0.0f);
	gcontext.Draw(r);
	gcontext.EndDraw();
	//glEnable(GL_DEPTH_TEST);

	/*
	Here's our rendering. Hopefully soon(tm)...
	*/





}