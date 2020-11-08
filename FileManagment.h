#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "NextPt.h"
#include "PreviousPkt.h"
#include "OperationOfDijkstra.h"

std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph);
std::vector<int> inputStartPkt(std::string fileWithStarts, std::map<int, std::vector<NextPt>> neighbors);
std::vector<int> findPrevious(int current, std::map<int, PreviousPkt> previousOne, int start);
void outputDijkstra(std::map<int, std::vector<NextPt>>neighbors, int startingPt, std::map<int, PreviousPkt> previousOne, std::string outputFile);