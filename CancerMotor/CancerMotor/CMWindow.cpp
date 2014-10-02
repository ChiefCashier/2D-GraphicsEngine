#include "CMWindow.h"

namespace CML
{

	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HGLRC ourOpenGLRenderingContext;
	HDC g_HDC;

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




						  return 0;
		}
		case WM_DESTROY:
		{
						   wglDeleteContext(ourOpenGLRenderingContext);
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

	}


	CMWindow::~CMWindow() //window destructor MARK 1 "The Eliminator"
	{
		/* I'm useful! */
	}


	HWND CMWindow::CMWindowHandle()// Return handle to the window
	{

		_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, _CLASS_NAME, L"CMWindow", WS_OVERLAPPEDWINDOW, 100, 100, _windowWidht, _windowHeight, //Windowhandle pointter creation
			NULL, NULL, GetModuleHandle(nullptr), NULL);

		if (_windowHandle == nullptr)//if window handle creation did not succeed, then do something about it will ya! 
		{

			//laittakaa debugloggerointia!

			std::cout << "Window handle creation failed" << std::endl; //Window creation failed so message is sent
			return nullptr;
		}
		return _windowHandle;


	}


	void CMWindow::Render()
	{
		/*
		Enable depth testing
		*/
		glEnable(GL_DEPTH_TEST);

		/*
		Heres our rendering. Hopefully soon(tm)...
		*/
		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		glFlush();

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
			Render();//this render is at a wrong place move it somewhere else preferably to main()
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}