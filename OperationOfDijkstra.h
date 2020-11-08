#pragma once
#include <map>
#include <vector>
#include "NextPt.h"
#include "PreviousPkt.h"
#include "Dijkstra.h"
#include "FileManagment.h"

std::map<int, std::map<int, double>> mapToMatrix(std::map<int, std::vector<NextPt>>neighbors);
int findMin(std::map<int, PreviousPkt> previousOne);
bool isExistingPt(std::map<int, std::vector<NextPt>> neighbors, int start);
void operationOfDijkstra(std::string fileWithGraph, std::string fileWithStarts,  std::string outputFile);