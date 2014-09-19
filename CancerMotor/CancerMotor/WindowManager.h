#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <iostream>
#include "glew.h"
namespace CML
{
	
	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HGLRC ourOpenGLRenderingContext;
	HDC g_HDC;
	class WindowManager
	{
	public:

		
		 WindowManager();
		HWND WindowMaker();
		~WindowManager();
		void ShowCMWindow(HWND);
		void WindowMessageCheck();
		void Render();

		void DrawCube(float xPos, float yPos, float zPos);
		void DrawHead(float xPos, float yPos, float zPos);
	private:
		HWND _windowHandle;



	};

	WindowManager::WindowManager()
	{
		
	}

	WindowManager::~WindowManager()
	{

	}
	void WindowManager::Render()
{
        /*      Enable depth testing
        */
        glEnable(GL_DEPTH_TEST);

        /*      Heres our rendering. Clears the screen
                to black, clear the color and depth
                buffers, and reset our modelview matrix.
        */
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();


        glPushMatrix();
                glLoadIdentity();

                /*      Move to 0,0,-30 , rotate the robot on
                        its y axis, draw the robot, and dispose
                        of the current matrix.
                */
				//DrawCube(50.0f, 50.0f, 50.0f);
				DrawHead(0.5f, 0.5f, 0.0f);
        glPopMatrix();

        glFlush();

        /*      Bring back buffer to foreground
        */
        SwapBuffers(g_HDC);
}
	void WindowManager::DrawHead(float xPos, float yPos, float zPos)
	{
		glPushMatrix();

		/*      Sets color to white*/
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(xPos, yPos, zPos);

		/*      Creates 2 x 2 x 2 cube*/
		glScalef(1.0f, 1.0f, 1.0f);
		DrawCube(0.0f, 0.0f, 0.0f);

		glPopMatrix();
	}
	void WindowManager::DrawCube(float xPos, float yPos, float zPos)
	{
		glPushMatrix();
		glBegin(GL_POLYGON);

		/*      This is the top face*/
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, 0.0f, 0.0f);

		/*      This is the front face*/
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, 0.0f);

		/*      This is the right face*/
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, -1.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);

		/*      This is the left face*/
		glVertex3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);

		/*      This is the bottom face*/
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);

		/*      This is the back face*/
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 0.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(0.0f, -1.0f, -1.0f);

		glEnd();
		glPopMatrix();
	}

	/*      Function:       DrawArm
	Purpose:        This function draws the arm
	for the robot.
	*/


	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
				32,                        //Colordepth of the framebuffer.
				0, 0, 0, 0, 0, 0,
				0,
				0,
				0,
				0, 0, 0, 0,
				24,                        //Number of bits for the depthbuffer
				8,                        //Number of bits for the stencilbuffer
				0,                        //Number of Aux buffers in the framebuffer.
				PFD_MAIN_PLANE,
				0,
				0, 0, 0
			};

			HDC ourWindowHandleToDeviceContext = GetDC(asd);
			g_HDC = ourWindowHandleToDeviceContext;
			int  letWindowsChooseThisPixelFormat;
			letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
			SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

			ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
			wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

			MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);

			
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

	HWND WindowManager::WindowMaker()
	{
		const wchar_t CLASS_NAME[] = L"asd";

		WNDCLASS wc = {};

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);//ikkunan rekisteröinti ilman tätä se ei onnistu
		_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, CLASS_NAME, L"asd", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, //ikkunakahva pointteri
			NULL, NULL, GetModuleHandle(nullptr), NULL);

		if (_windowHandle == nullptr)
		{
			std::cout << "Window creation failed" << std::endl; //Ikkunan luominen eäonnistui, joten siitä lähetetään virhe ilmoitus
			return nullptr;
		}
		return _windowHandle;


	}
	void WindowManager::ShowCMWindow(HWND asd)
	{
		ShowWindow(asd, SW_SHOWNORMAL);
	}
	void WindowManager::WindowMessageCheck(){
		MSG msg;
	
		while (PeekMessage(&msg, _windowHandle, NULL, NULL, PM_REMOVE))
		{
			Render();
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

}