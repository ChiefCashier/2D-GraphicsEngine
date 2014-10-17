#include "CMWindow.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include <cassert>

namespace CML
{
		"uniform mat4 unifProjection; \n"

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

		const GLint _samplerLocation = glGetUniformLocation(_program, "myTexture");
		assert(_samplerLocation >= 0);

		const GLint _projectionLocation = glGetUniformLocation(_program, "unifProjection");
			GL_UNSIGNED_BYTE, FreeImage_GetBits(sprite2.GetImage().getBITMAP()));
		//Create projection

		const glm::mat4 _projection = glm::ortho(0.0f, static_cast<float>(windowWidht), 0.0f, static_cast<float>(windowHeight), -1.0f, 1.0f);
		glUseProgram(_program);
		glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

		glUseProgram(0u);


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