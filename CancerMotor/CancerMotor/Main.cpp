#include "ResourceManager.h"
#include "glm\glm.hpp"
#include <string>
#include <iostream>
#include "WindowManager.h"

int main()
{
	/*
	char *a = CML::ResourceManager::LoadFile("testi.txt");
	std::string b = a;
	for (unsigned int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}
	WindowManager a;
	a.create();
	*/

	CML::WindowManager window;
	HWND asd = window.WindowMaker();
	window.ShowCMWindow(asd);
	while (true)
		window.WindowMessageCheck();
	//poista kun debugger luokka valmis
	//system("PAUSE");
	return 0;
}