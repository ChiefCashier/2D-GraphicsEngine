#include "CMWindow.h"
#include "ResourceManager.h"
#include "glm\glm.hpp"
#include <string>
#include <iostream>


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

	CML::CMWindow window(0, L"asd", 800, 600);
	window.ShowCMWindow();
	CML::CMWindow window2(0, L"asd", 400, 300);
	window2.ShowCMWindow();

	while (true)
	{
		window.Render();
		window.WindowMessageCheck();
		window2.Render();
		window2.WindowMessageCheck();
	}
		
	//poista kun debugger luokka valmis
	//system("PAUSE");
	return 0;
}