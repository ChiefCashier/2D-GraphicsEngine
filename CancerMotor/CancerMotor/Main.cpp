#include "CMWindow.h"
#include "glew.h"
#include "ResourceManager.h"
#include "glm\glm.hpp"
#include "CMSprite.h"
#include <string>
#include <iostream>
#include "RenderingContext.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
	GLuint _texture;
	GLint _positionIndex;
	GLint _colorIndex;
	GLint _textureIndex;


	GLuint buffers[2];
	RenderingContext rendContext;
void Render(HWND asd);
int main()
{
	// kaikki on paskaa
	




	CML::CMWindow window(0, L"asd", 800, 600);
	window.ShowCMWindow();
	rendContext = RenderingContext(&window);







	//Here lies componets for rendering
















	//activate attribute arrays
	_positionIndex = glGetAttribLocation(rendContext.getProgramIndex(), "attrPosition");
	assert(_positionIndex >= 0);
	glEnableVertexAttribArray(_positionIndex);

	_colorIndex = glGetAttribLocation(rendContext.getProgramIndex(), "attrColor");
	assert(_colorIndex >= 0);
	glEnableVertexAttribArray(_colorIndex);

	_textureIndex = glGetAttribLocation(rendContext.getProgramIndex(), "attrTexCoord");
	assert(_textureIndex >= 0);
	glEnableVertexAttribArray(_textureIndex);


	const GLint _samplerLocation = glGetUniformLocation(rendContext.getProgramIndex(), "myTexture");
	assert(_samplerLocation >= 0);

	const GLint _projectionLocation = glGetUniformLocation(rendContext.getProgramIndex(), "unifProjection");

	//texture stuff

	glGenTextures(1, &_texture);//generates texture

	//_texture = glGetUniformLocation(_program, "myTexture"); 
	//assert(_texture >= 0);



	CML::CMSprite sprite = CML::CMSprite::CMSprite(0.0f, 0.0f, 200.0f, 150.0f, "Sample.png");
	CML::CMSprite sprite2 = CML::CMSprite::CMSprite(200.0f, 150.0f, 400.0f, 300.0f, "Sample.png");

	glTexImage2D(GL_TEXTURE_2D, 0, 4, sprite2.GetImage().getWidth(), sprite2.GetImage().getHeight(), 0, sprite2.GetImage().getImageFormat(), GL_UNSIGNED_BYTE, FreeImage_GetBits(sprite2.GetImage().getBITMAP()));

	glBindTexture(rendContext.getProgramIndex(), _texture);

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




	if (_vertexBufferInput) //this is the data given to vertex buffer, rename as needed
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexBufferInput), _vertexBufferInput, GL_STATIC_DRAW);//sizeof(_vertexBufferInput) might return a value that is not always correct...
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		std::cout << "vertexBufferInput works, yay" << std::endl;
	}

	GLint _fragmentBufferInput[6] = { 0u, 1u, 2u, 2u, 3u, 0u,};

	if (_fragmentBufferInput) //this is the data given to fragment buffer, rename as needed
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_fragmentBufferInput), _fragmentBufferInput, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		std::cout << "FragmentBufferInput works too, another yay" << std::endl;
	}



	const glm::mat4 _projection = glm::ortho(0.0f, static_cast<float>(window._windowWidht) , 0.0f, static_cast<float>(window._windowHeight), -1.0f, 1.0f);

	glUseProgram(rendContext.getProgramIndex());
	glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

	glUseProgram(0u);





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
	wglMakeCurrent(GetDC(windowh), rendContext.getRenderingContext());
	//glEnable(GL_DEPTH_TEST);

	/*
	Here's our rendering. Hopefully soon(tm)...
	*/



	glFlush();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(rendContext.getProgramIndex());



	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

	glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

	glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

	glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

	glBindTexture(rendContext.getProgramIndex(), _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));
	glBindTexture(rendContext.getProgramIndex(), 0u);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glUseProgram(0);

	SwapBuffers(rendContext.getHDC());//Bring back buffer to foreground

}