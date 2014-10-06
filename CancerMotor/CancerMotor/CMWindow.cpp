#include "CMWindow.h"
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

		"	gl_FragColor = vec4(varyColor, 0.0f); \n"
		"	gl_FragColor += texture2D(myTexture, vTexCoord).bgra; \n"

		"}\n";
	

	static const GLfloat VERTEX_DATA[] =
	{
		//1st vertex
		0.0f, 0.0f,
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
		0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 1.0f
	};

	static const GLuint INDEX_DATA[] =
	{
		//add index data
		0u, 1u, 2u, 3u
	};

	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HGLRC ourOpenGLRenderingContext;
	HDC g_HDC;
	GLuint buffers[2];

	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam) //without this nothing works, so I say we keep it
	{
		switch (uMsg){
		case WM_CREATE:
		{
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

						  HDC ourWindowHandleToDeviceContext = GetDC(asd);// 
						  g_HDC = ourWindowHandleToDeviceContext;
						  int  letWindowsChooseThisPixelFormat;
						  letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
						  SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

						  ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
						  wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);


						  glewInit();

						  return 0;
		}
		case WM_DESTROY:
		{
						   wglDeleteContext(ourOpenGLRenderingContext);
						   glDeleteBuffers(2, buffers);
						   PostQuitMessage(0);
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

		if (_windowHandle == nullptr)//if window handle creation did not succeed, then do something about it will ya! 
		{

			//laittakaa debugloggerointia!


			std::cout << "Window handle creation failed" << std::endl; //Window handle creation failed so message is sent

		}
	}

	CMWindow::CMWindow()//default constructor for window
	{

		WNDCLASS wc = {};

		_CLASS_NAME = L"asd";
		_windowWidht = 800;
		_windowHeight = 600;

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.lpszClassName = _CLASS_NAME;

		RegisterClass(&wc);

		_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, _CLASS_NAME, L"CMWindow", WS_OVERLAPPEDWINDOW, 100, 100, _windowWidht, _windowHeight, //Windowhandle pointter creation
			NULL, NULL, GetModuleHandle(nullptr), NULL);

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

		CML::CMImage image = CML::CMImage::CMImage("sample.png");
		
		glTexImage2D(_texture, 1, 0, image.getWidth(), image.getHeight(), 0, image.getImageFormat(), GL_UNSIGNED_BYTE, image.getPixelData());
		glBindTexture(_program, _texture);

	
		//Buffers
		glGenBuffers(2, buffers);

		//change multiplier for sizeof(GLfloat) according to VERTEX_DATA
		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		glBufferData(GL_ARRAY_BUFFER, 28 * sizeof(GLfloat), VERTEX_DATA, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//change multiplier for sizeof(GLint) according to INDEX_DATA
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLint), INDEX_DATA, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);








	}


	CMWindow::~CMWindow() //window destructor MARK 1 "The Eliminator"
	{
		/* I'm useful! */
	}


	HWND CMWindow::CMWindowHandle()// Return handle to the window
	{
		return _windowHandle;
	}


	void CMWindow::Render()
	{
		/*
		Enable depth testing
		*/

		glEnable(GL_DEPTH_TEST);

		/*
		Here's our rendering. Hopefully soon(tm)...
		*/

		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		

		glFlush();

		glUseProgram(_program);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

		glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

		glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
		glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));


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