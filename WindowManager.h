#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <iostream>

namespace CML
{
	
	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	class WindowManager
	{
	public:

		
		 WindowManager();
		HWND WindowMaker();
		~WindowManager();
		void ShowCMWindow(HWND);
		void WindowMessageCheck();
	private:
		HWND _windowHandle;

	};

	WindowManager::WindowManager()
	{
		
	}

	WindowManager::~WindowManager()
	{

	}

	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg){
		case WM_CREATE:
			return 0;
		case WM_DESTROY:
		{
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

		RegisterClass(&wc);//ikkunan rekister�inti ilman t�t� se ei onnistu
		_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, CLASS_NAME, L"asd", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, //ikkunakahva pointteri
			NULL, NULL, GetModuleHandle(nullptr), NULL);

		if (_windowHandle == nullptr)
		{
			std::cout << "Window creation failed" << std::endl; //Ikkunan luominen e�onnistui, joten siit� l�hetet��n virhe ilmoitus
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
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

}