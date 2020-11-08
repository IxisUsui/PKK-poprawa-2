
#include <iostream>
#include <vector>
#include <map>
#include "NextPt.h"
#include "PreviousPkt.h"
#include "OperationOfDijkstra.h"

std::map<int, PreviousPkt>  dijkstra(std::map<int, std::vector<NextPt>> neighbors, int start, std::map<int, std::map<int, double>> matrix);

