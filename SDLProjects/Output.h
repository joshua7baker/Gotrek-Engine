#pragma once
#include <iostream>

class Output
{
public :
	static void PrintMessage(std::string message);
	static void PrintError(std::string message, const char* messageTwo);
};

