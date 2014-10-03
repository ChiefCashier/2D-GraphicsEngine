#include "ResourceManager.h"
#include "FreeImage.h"
#include <iostream>
#include <fstream>
#include <cassert>
/*
Parametrit:
filename: tiedoston nimi ja p‰‰te esim: "kuva.png"

Metodi:
K‰ytt‰‰ FreeImagea kuvien lataamiseen suoraan merkkijonoon.

*/

namespace CML{
	char* CML::ResourceManager::LoadImage(char* filename)
	{


		FREE_IMAGE_FORMAT formato = FreeImage_GetFIFFromFilename(filename);
		FIBITMAP* imagen = FreeImage_Load(formato, filename);


		char* pixeles = (char*)FreeImage_GetBits(imagen);
		FreeImage_Unload(imagen);
		return pixeles;
	}

	/*
	Parametrit:
	filename: tiedoston nimi ja p‰‰te esim: "tiedosto.txt"

	Metodi:
	K‰ytt‰‰ ifstreami‰ tiedoston latamiseen, aukaisee tiedoston, etsii sen koon ja lukee datan.

	HUOM:
	bufferi pit‰‰ poistaa k‰ytˆn j‰lkeen

	Myˆhemmin pit‰‰ suojata erroreilta kuten tiedostoa ei ole

	*/
	char* CML::ResourceManager::LoadFile(char* filename)
	{
		std::ifstream is(filename, std::ifstream::binary);
		assert(is);
		if (is) {
			// tiedoston koko
			is.seekg(0, is.end);
			int length = is.tellg();
			is.seekg(0, is.beg);

			char * buffer = new char[length + 1];

			std::cout << "Reading " << length << " characters... ";
			// lukee tiedoston datan
			is.read(buffer, length);

			buffer[length] = 0;
			if (is)
				std::cout << "all characters read successfully.";
			else
				std::cout << "error: only " << is.gcount() << " could be read";
			is.close();

			// buffer pit‰‰ poistaa k‰ytˆn j‰lkeen
			return buffer;
		}
		
		return NULL;
	}
}