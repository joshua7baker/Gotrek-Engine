#include "Output.h"

void Output::PrintMessage(std::string message)
{
	std::cout << message << std::endl;
}

void Output::PrintError(std::string message, const char* messageTwo)
{
	std::cout << message << " Error: " << messageTwo << std::endl;
}