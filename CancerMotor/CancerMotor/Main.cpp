#include "CMWindow.h"
#include "glew.h"
#include "ResourceManager.h"
#include "glm\glm.hpp"
#include "CMSprite.h"
#include <string>
#include <iostream>

GLuint _program;
	GLuint _texture;
	GLint _positionIndex;
	GLint _colorIndex;
	GLint _textureIndex;
	HGLRC ourOpenGLRenderingContext;
	HDC g_HDC;
	GLuint buffers[2];

void Render(HWND asd);
int main()
{
	// kaikki on paskaa
	




	CML::CMWindow window(0, L"asd", 800, 600);
	window.ShowCMWindow();

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		24,                        //Colordepth of the framebuffer.		
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE
	};

	HDC ourWindowHandleToDeviceContext = GetDC(window.CMWindowHandle());// 
	g_HDC = ourWindowHandleToDeviceContext;
	int  letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
	SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

	ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
	wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);


	glewInit();


	if (window.CMWindowHandle() == nullptr)//if window handle creation did not succeed, then do something about it will ya! 
	{

		//laittakaa debugloggerointia!


		std::cout << "Window handle creation failed" << std::endl; //Window handle creation failed so message is sent

	}

	_program = glCreateProgram();


	//Here lies componets for rendering


	//read VERTEX_SOURCE from file
	GLchar* vertexBuffer = CML::ResourceManager::LoadFile("VertexSource.txt");

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexBuffer, nullptr);
	glCompileShader(vertexShader);

	GLint compileResult;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileResult);
	assert(compileResult == GL_TRUE);

	//read FRAGMENT_SOURCE from file
	GLchar* fragmentBuffer = CML::ResourceManager::LoadFile("FragmentSource.txt");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentBuffer, nullptr);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileResult);
	assert(compileResult == GL_TRUE);

	glAttachShader(_program, vertexShader);
	glAttachShader(_program, fragmentShader);
	glLinkProgram(_program);

	glGetProgramiv(_program, GL_LINK_STATUS, &compileResult);
	assert(compileResult == GL_TRUE);

	//activate attribute arrays
	_positionIndex = glGetAttribLocation(_program, "attrPosition");
	assert(_positionIndex >= 0);
	glEnableVertexAttribArray(_positionIndex);

	_colorIndex = glGetAttribLocation(_program, "attrColor");
	assert(_colorIndex >= 0);
	glEnableVertexAttribArray(_colorIndex);

	_textureIndex = glGetAttribLocation(_program, "attrTexCoord");
	assert(_textureIndex >= 0);
	glEnableVertexAttribArray(_textureIndex);


	//texture stuff

	glGenTextures(1, &_texture);//generates texture

	//_texture = glGetUniformLocation(_program, "myTexture"); 
	//assert(_texture >= 0);



	CML::CMSprite sprite = CML::CMSprite::CMSprite(0.0f, 0.0f, 200.0f, 150.0f, "Sample.png");
	CML::CMSprite sprite2 = CML::CMSprite::CMSprite(200.0f, 150.0f, 400.0f, 300.0f, "Sample.png");

	glTexImage2D(GL_TEXTURE_2D, 0, 4, sprite2.GetImage().getWidth(), sprite2.GetImage().getHeight(), 0, sprite2.GetImage().getImageFormat(), GL_UNSIGNED_BYTE, FreeImage_GetBits(sprite2.GetImage().getBITMAP()));

	glBindTexture(_program, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0u);

	glActiveTexture(GL_TEXTURE0);



	//Buffers
	glGenBuffers(2, buffers);
	/*
	if(puffer)assert puffer

	puffer.koko / 7 = vertexcount

	glBufferData(GL_ARRAY_BUFFER, 7 * vertexcountsizeof(GLfloat), VERTEX_DATA, GL_STATIC_DRAW);

	else

	teejotainjuttuja()
	*/
		int _windowHeight = 600;
		int _windowWidht = 800;

	//Data, in order: 2x position, 3x colour, 2x texture coordinates
	GLfloat _vertexBufferInput[] = {

		//clean and simple

		//-1.0f, -1.0f,
		//0.0f, 0.0f, 0.0f,
		//0.0f, 0.0f,

		//-1.0f, 1.0f,
		//0.0f, 0.0f, 0.0f,
		//0.0f, 1.0f,

		//1.0f, 1.0f, 
		//0.0f, 0.0f, 0.0f,
		//1.0f, 1.0f,

		//1.0f, -1.0f,
		//0.0f, 0.0f, 0.0f,
		//1.0f, 0.0f

		//not so clean and simple...
		


		((sprite.GetX() / _windowWidht) * 2) - 1, ((sprite.GetY() / _windowHeight) * 2) - 1,					// here sprite positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		(sprite.GetTexturePositionX() / _windowWidht), (sprite.GetTexturePositionY() / _windowHeight),			// here sprite texture positions are transformed to opengl format 

		((sprite.GetX() / _windowWidht) * 2) - 1, ((sprite.GetHeight() / _windowHeight) * 2) - 1,				// here sprite positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		(sprite.GetTexturePositionX() / _windowWidht), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),				// here sprite texture positions are transformed to opengl format 

		((sprite.GetWidht() / _windowWidht) * 2) - 1, ((sprite.GetHeight() / _windowHeight) * 2) - 1,			// here sprite positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		sprite.GetTextureWidht() / sprite.GetImage().getWidth(), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),		// here sprite positions are transformed to opengl format 

		((sprite.GetWidht() / _windowWidht) * 2) - 1, ((sprite.GetY() / _windowHeight) * 2) - 1,				// here sprite texture positions are transformed to opengl format 
		sprite.GetColorRed(), sprite.GetColorGreen(), sprite.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		sprite.GetTextureWidht() / sprite.GetImage().getWidth(), (sprite.GetTexturePositionY() / _windowHeight),				// here sprite positions are transformed to opengl format 





		((sprite2.GetX() / _windowWidht) * 2) - 1, ((sprite2.GetY() / _windowHeight) * 2) - 1,					// here sprite positions are transformed to opengl format 
		sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		(sprite2.GetTexturePositionX() / _windowWidht), (sprite2.GetTexturePositionY() / _windowHeight),		// here sprite texture positions are transformed to opengl format 

		((sprite2.GetX() / _windowWidht) * 2) - 1, ((sprite2.GetHeight() / _windowHeight) * 2) - 1,				// here sprite positions are transformed to opengl format 
		sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		(sprite2.GetTexturePositionX() / _windowWidht), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),			// here sprite texture positions are transformed to opengl format 

		((sprite2.GetWidht() / _windowWidht) * 2) - 1, ((sprite2.GetHeight() / _windowHeight) * 2) - 1,			// here sprite positions are transformed to opengl format 
		sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		sprite.GetTextureWidht() / sprite.GetImage().getWidth(), sprite.GetTextureHeight() / sprite.GetImage().getHeight(),		// here sprite texture positions are transformed to opengl format 

		((sprite2.GetWidht() / _windowWidht) * 2) - 1, ((sprite2.GetY() / _windowHeight) * 2) - 1,				// here sprite positions are transformed to opengl format 
		sprite2.GetColorRed(), sprite2.GetColorGreen(), sprite2.GetColorBlue(),									// here sprite colors are transformed to opengl format 
		sprite.GetTextureWidht() / sprite.GetImage().getWidth(), (sprite2.GetTexturePositionY() / _windowHeight)				// here sprite texture positions are transformed to opengl format 

	};




	if (_vertexBufferInput) //this is the data given to vertex buffer, rename as needed
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexBufferInput), _vertexBufferInput, GL_STATIC_DRAW);//sizeof(_vertexBufferInput) might return a value that is not always correct...
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		std::cout << "vertexBufferInput works, yay" << std::endl;
	}

	GLint _fragmentBufferInput[12] = { 0u, 1u, 2u, 2u, 3u, 0u, 4u, 5u, 6u, 6u, 7u, 4u };

	if (_fragmentBufferInput) //this is the data given to fragment buffer, rename as needed
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_fragmentBufferInput), _fragmentBufferInput, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		std::cout << "FragmentBufferInput works too, another yay" << std::endl;
	}







	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	HWND asd = window.CMWindowHandle();

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
	wglMakeCurrent(GetDC(windowh), ourOpenGLRenderingContext);
	//glEnable(GL_DEPTH_TEST);

	/*
	Here's our rendering. Hopefully soon(tm)...
	*/



	glFlush();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(_program);



	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

	glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

	glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

	glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

	glBindTexture(_program, _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));
	glBindTexture(_program, 0u);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glUseProgram(0);

	SwapBuffers(g_HDC);//Bring back buffer to foreground

}