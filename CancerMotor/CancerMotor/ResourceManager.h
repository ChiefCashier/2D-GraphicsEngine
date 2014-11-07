#pragma once
#include <map>
#include "Resource.h"
#include "CMImage.h"
namespace CML{
	class ResourceManager
	{
	public:
		static char* LoadFile(char* filename);
		static char* LoadImage(char* filename);
		static CMImage createImage(char* filename);
	private:
		static std::map<std::string, Resource*> _resources;
	};

}