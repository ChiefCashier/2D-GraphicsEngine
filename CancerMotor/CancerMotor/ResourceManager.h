#pragma once
namespace CML{
	class ResourceManager
	{
	public:
		static char* LoadFile(char* filename);
		static char* LoadImage(char* filename);

	};

}