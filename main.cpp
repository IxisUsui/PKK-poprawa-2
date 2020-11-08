#include <iostream>
#include <fstream>
#include <string>
#include "OperationOfDijkstra.h"
#include "CommandLineManagament.h"

int main(int argc, char **argv)
{
	std::string fileWithGraph,fileWithStarts, outputFile;
	if (argc == 1 or (std::string(argv[1]) == "-h" and argc == 2))
	{
		showHelp();
	}
	if (argc == 7)
	{
		for (int i = 1; i < argc; i++)
		{
			if (std::string(argv[i]) == "-g")
			{

				fileWithGraph = argv[++i];
			}
			else if (std::string(argv[i]) == "-w")
			{
				fileWithStarts = argv[++i];
			}
			else if (std::string(argv[i]) == "-o")
			{
				outputFile = argv[++i];
			}
			else
			{
				std::cout << "Wpisano błedne argumenty";
				return 1;
			}
		}
	}
	else 
	{
		std::cout << "za mało argumentow programu";
		return 1;
	}
	operationOfDijkstra(fileWithGraph, fileWithStarts, outputFile);
	return 0;
}