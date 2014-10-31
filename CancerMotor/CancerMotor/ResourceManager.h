#pragma once
#include <map>
#include <string>
namespace CML{
	class ResourceManager
	{
	public:
		static char* LoadFile(char* filename);
		static char* LoadImage(char* filename);
	private:
		std::map<std::string, int*> _resources;
	};

}