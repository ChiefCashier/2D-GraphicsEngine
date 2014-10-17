#include "CMWindow.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include <cassert>

namespace CML
{
	//these can be read from file
	static const GLchar* VERTEX_SOURCE =
		"attribute vec2 attrPosition; \n"
		"attribute vec3 attrColor; \n"
		"attribute vec2 attrTexCoord; \n"

		"varying vec3 varyColor; \n"
		"varying vec2 vTexCoord; \n"

		"uniform mat4 unifProjection; \n"

		"void main()\n"
		"{\n"
		"	varyColor = attrColor; \n"
		"	vTexCoord = attrTexCoord; \n"
		"	gl_Position = vec4(attrPosition, 0.0f, 1.0f); \n"
		"}\n";

	static const GLchar* FRAGMENT_SOURCE =
		"uniform sampler2D myTexture; \n"

		"varying vec3 varyColor; \n"
		"varying vec2 vTexCoord; \n"
		
		"void main()\n"
		"{\n"

		"	gl_FragColor = vec4(varyColor, 0.0f) + texture2D(myTexture, vTexCoord); \n"
		//"	gl_FragColor ; \n"

		"}\n";
	
	
	static const GLfloat VERTEX_DATA[] =
	{
		//1st vertex
		-0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f,

		//2nd vertex
		1.0f, -0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f,

		//3rd vertex
		1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f,
		
		//4th vertex
		-0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 1.0f
	};
	
	static const GLuint INDEX_DATA[] =
	{
		//add index data
		0u, 1u, 2u, 3u
	};
	

	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam);


	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam) //without this nothing works, so I say we keep it
	{
		switch (uMsg){
		case WM_CREATE:
		{
						  return 0;
		}
		case WM_DESTROY:
		{
						   //wglDeleteContext(ourOpenGLRenderingContext);
						   //glDeleteBuffers(2, buffers);
						   PostQuitMessage(0);
						   DestroyWindow(asd);
						   return 0;
		}
		default:

			return DefWindowProc(asd, uMsg, wParam, lParam);

		}
		

	}

	CMWindow::CMWindow(int windowType, const wchar_t* CLASS_NAME, int windowWidht, int windowHeight)//constructor for window with "parameters"
	{
		

		WNDCLASS wc = {};

		_CLASS_NAME = CLASS_NAME;
		_windowWidht = windowWidht;
		_windowHeight = windowHeight;

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.lpszClassName = _CLASS_NAME;

		RegisterClass(&wc);

		_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, _CLASS_NAME, L"CMWindow", WS_OVERLAPPEDWINDOW, 100, 100, _windowWidht, _windowHeight, //Windowhandle pointter creation
			NULL, NULL, GetModuleHandle(nullptr), NULL);

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

		HDC ourWindowHandleToDeviceContext = GetDC(_windowHandle);// 
		g_HDC = ourWindowHandleToDeviceContext;
		int  letWindowsChooseThisPixelFormat;
		letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
		SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

		ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
		wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);


		glewInit();


		if (_windowHandle == nullptr)//if window handle creation did not succeed, then do something about it will ya! 
		{

			//laittakaa debugloggerointia!


			std::cout << "Window handle creation failed" << std::endl; //Window handle creation failed so message is sent

		}

		_program = glCreateProgram();


		//Here lies componets for rendering


		//read VERTEX_SOURCE from file
		//GLchar* vertexBuffer = CML::ResourceManager::LoadFile("VertexSource.txt");

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &VERTEX_SOURCE, nullptr);
		glCompileShader(vertexShader);

		GLint compileResult;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileResult);
		assert(compileResult == GL_TRUE);

		//read FRAGMENT_SOURCE from file
		//GLchar* fragmentBuffer = CML::ResourceManager::LoadFile("FragmentSource.txt");

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &FRAGMENT_SOURCE, nullptr);
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

		const GLint _samplerLocation = glGetUniformLocation(_program, "myTexture");
		assert(_samplerLocation >= 0);

		const GLint _projectionLocation = glGetUniformLocation(_program, "unifProjection");

		//texture stuff

		glGenTextures(1, &_texture);//generates texture

		//_texture = glGetUniformLocation(_program, "myTexture"); 
		//assert(_texture >= 0);


		
		CMSprite sprite = CMSprite::CMSprite(0.0f, 0.0f, 200.0f, 150.0f,"Sample.png");
		CMSprite sprite2 = CMSprite::CMSprite(200.0f, 150.0f, 400.0f, 300.0f, "Sample.png");
		
		glTexImage2D(GL_TEXTURE_2D, 0, 4, sprite2.GetImage().getWidth(), sprite2.GetImage().getHeight(), 0, sprite2.GetImage().getImageFormat(), 
			GL_UNSIGNED_BYTE, FreeImage_GetBits(sprite2.GetImage().getBITMAP()));

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


		//Data, in order: 2x position, 3x colour, 2x texture coordinates
		GLfloat _vertexBufferInput[56] = { 

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

		else
		{
			//change multiplier for sizeof(GLfloat) according to VERTEX_DATA
			glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
			glBufferData(GL_ARRAY_BUFFER, 28 * sizeof(GLfloat), VERTEX_DATA, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			std::cout << "VERTEX_DATA used" << std::endl;
		}
		GLint _fragmentBufferInput[12] = { 0u, 1u, 2u, 2u, 3u, 0u, 4u, 5u, 6u, 6u, 7u, 4u};

		if (_fragmentBufferInput) //this is the data given to fragment buffer, rename as needed
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_fragmentBufferInput), _fragmentBufferInput, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			std::cout << "FragmentBufferInput works too, another yay" << std::endl;
		}

		else
		{
			//change multiplier for sizeof(GLint) according to INDEX_DATA
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLint), INDEX_DATA, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			std::cout << "INDEX_DATA used" << std::endl;
		}

		//Create projection

		const glm::mat4 _projection = glm::ortho(0.0f, static_cast<float>(windowWidht), 0.0f, static_cast<float>(windowHeight), -1.0f, 1.0f);

		glUseProgram(_program);
		glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

		glUseProgram(0u);





		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	}
	

	CMWindow::CMWindow()//default constructor for window
	{
		CMWindow(0, L"asd", 800, 600);
	}


	CMWindow::~CMWindow() //window destructor MARK 1 "The Eliminator"
	{
		/* I'm useful! */
		delete(_windowHandle);
	}


	HWND CMWindow::CMWindowHandle()// Return handle to the window
	{
		return _windowHandle;
	}


	void CMWindow::Render()
	{
		wglMakeCurrent(GetDC(_windowHandle), ourOpenGLRenderingContext);
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





	void CMWindow::ShowCMWindow()//Showing the window since 2014
	{
		ShowWindow(_windowHandle, SW_SHOWNORMAL);//"Another witty comment about the code"
	}


	void CMWindow::WindowMessageCheck(){
		MSG msg;//I don't even...

		while (PeekMessage(&msg, _windowHandle, NULL, NULL, PM_REMOVE))
		{
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}