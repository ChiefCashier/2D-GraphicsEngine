#pragma once

#ifndef WIN32_LEAN_AND_MEAN 
#define WIN32_LEAN_AND_MEAN //How lean and how mean?
#endif

#include "glew.h"
//debuglogger is away until fixed
//#include "DebugLogger.h" 
#include <Windows.h>
#include <iostream>


namespace CML
{
	class CMWindow
	{
	public:
		
		//constructors
		CMWindow();
		CMWindow(int windowType, const wchar_t* CLASS_NAME,
				 int windowWidht, int windowHeight);
		//destructors
		~CMWindow();

		//window handle makers
		HWND CMWindowHandle();

		//and the rest
		void ShowCMWindow();
		void WindowMessageCheck();
		void Render();//renaming under consideration. "Our top men are on the case!"

	private:

		//things and stuff
		wchar_t _windowName;
		int _windowWidht, _windowHeight;
		int _windowType;
		const wchar_t* _CLASS_NAME;
		
		//thingamabob(s)
		HWND _windowHandle;
	};
}