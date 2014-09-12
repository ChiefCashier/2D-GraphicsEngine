#include <iostream>
#include <fstream>
#include <string>


void WriteToFile(std::ofstream &outputFile, std::string msg)
{
	outputFile << msg << std::endl;
}

int main()
{
	std::ofstream outputFile;
	outputFile.open("ErrorLog.txt");
	if (outputFile.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			WriteToFile(outputFile, "This is a test message 3.4");
		}
		outputFile.close();
	}
	return 0;
}