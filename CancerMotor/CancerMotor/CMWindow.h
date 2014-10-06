#pragma once

#ifndef WIN32_LEAN_AND_MEAN 
#define WIN32_LEAN_AND_MEAN //How lean and how mean?
#endif

//debuglogger is away until fixed
//#include "DebugLogger.h" 
#include <Windows.h>
#include <iostream>

#include "glew.h"
#include "ResourceManager.h"
#include "CMImage.h"

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
		GLuint _program;
		GLuint _texture;
		GLint _positionIndex;
		GLint _colorIndex;
		GLint _textureIndex;

		//thingamabob(s)
		HWND _windowHandle;
	};
}