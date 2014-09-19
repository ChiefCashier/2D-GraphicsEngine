#include "ResourceManager.h"
#include <string>
#include <iostream>
#include <Windows.h>


int main()
{
	char *a = CML::ResourceManager::LoadFile("testi.txt");
	std::string b = a;
	for (unsigned int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}
	WindowManager a;
	a.create();
	//poista kun debugger luokka valmis
	system("PAUSE");
	return 0;
}