#pragma once
#include <map>
#include "Resource.h"
#include <string>
namespace CML{
	
	class ResourceManager
	{

	public:
		static char* LoadFile(char* filename);
		static char* LoadImage(char* filename);
		
		//template<typename T>
		//static T* createResource(char* filename)
		//{
		//	//_resources.find("test");

		//	//if (_resources.find(filename) == _resources.end())
		//	//{
		//	//	T *t =new T(filename);
		//	//	_resources.insert(std::make_pair<std::string, Resource*>(std::string(filename), t));
		//	//	return t;
		//	//}

		//	//std::map<std::string, Resource*>::iterator it = _resources.find(filename);

		//	//T* output = dynamic_cast<T*>(it->second);

		//	//return output;
		//}

	private:
		static std::map<std::string, Resource*> _resources;
	};

}