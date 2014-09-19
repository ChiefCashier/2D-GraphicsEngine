#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <Windows.h>

namespace CML
{
	bool WriteLog = false;
}
	class DebugLogger
	{
	public:
		static void Print(char *format, ...)
		{
			va_list marker;
			TCHAR szBuf[256];

			va_start(marker, format);
			vsprintf_s(szBuf, format, marker);
			va_end(marker);

			OutputDebugString(szBuf);
			OutputDebugString(TEXT("\n"));

			va_list arg;
			va_start(arg, format);
			vfprintf(stdout, format, arg);
			va_end(arg);

			std::basic_string<TCHAR> strName = szBuf;

			// If WriteLog is set true, write message to file
			if (CML::WriteLog)
				WriteToFile(strName);
		}

		// Write message to file
		static void WriteToFile(std::string msg)
		{
			std::ofstream outputFile;
			outputFile.open("ErrorLog.txt", std::ios::app);
			if (outputFile.is_open())
			{
				outputFile << msg << std::endl;
			}
			outputFile.close();
		}
	};
