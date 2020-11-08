#include "Dijkstra.h"

std::map<int, PreviousPkt> dijkstra (std::map<int, std::vector<NextPt>> neighbors, int start, std::map<int, std::map<int, double>> matrix)
{

	std::map<int, PreviousPkt > previousOne;
	PreviousPkt previous;
	for (auto& neighbor : neighbors)
	{
		int id = neighbor.first;
		previous.wasUsed = false;
		previous.previous = -1;
		previous.distance = (id == start) ? 0 : INT_MAX;
		previousOne[neighbor.first] = previous;
	}
	int min = findMin(previousOne);	
	while (min != -1)
	{
		previousOne[min].wasUsed = true;
		for (auto& previous : previousOne)
		{
			if (matrix[min][previous.first] > 0 and (previousOne[min].distance + matrix[min][previous.first]) < previous.second.distance)
			{
				previous.second.distance = previousOne[min].distance + matrix[min][previous.first];
				previous.second.previous = min;
			}
		}	
		min = findMin(previousOne);
	}
	return previousOne;
}



