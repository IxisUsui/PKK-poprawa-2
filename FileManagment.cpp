#include "FileManagment.h"

//wpisywanie do pliku
std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph)
{
    std::map<int, std::vector<NextPt>> neighbors;
    std::map<int, std::vector<NextPt>> inputGraf(std::string fileWithGraph);
    NextPt next;
    int startPt;
    std::string edge;
    int nextPt;
    double distance;
    char colon;

    std::ifstream file;
    file.open(fileWithGraph);
    if (file.good())
    {

        while (file >> startPt >> edge >> nextPt >> colon >> distance)
        {
            if (edge == "-") //tworzenie punktow o nieskierowanej krawiedzi
            {
                next.nextPt = nextPt;
                next.distance = distance;
                neighbors[startPt].push_back(next);
                next.nextPt = startPt;
                next.distance = distance;
                neighbors[nextPt].push_back(next);
            }
            else //tworzenie pkt o skierowanej krawedzi
            {
            next.nextPt = nextPt;
            next.distance = distance;
            neighbors[startPt].push_back(next);
            }
        }
    }
    else
    {
        std::cout << "otwarcie pliku: ' " << fileWithGraph << " ' nie powiodlo sie" << std::endl;
    }
    file.close();
    return neighbors;
}

std::vector<int> inputStartPkt(std::string fileWithStarts, std::map<int,std::vector<NextPt>> neighbors) 
{
    std::ifstream file;
    file.open(fileWithStarts);
    std::vector<int> startingPt;
    int point;
    NextPt next;

    if (file.good())
    {
        while (file >> point)
        {
            startingPt.push_back(point);
            next.nextPt = point;
            next.distance = 0;
            neighbors[point].push_back(next);
        }
    }
    else
    {
        std::cout << "otwarcie pliku: ' " << fileWithStarts << " ' nie powiodlo sie" << std::endl;
    }
    file.close();
    return startingPt;
}

// wypisywanie do pliku
std::vector<int> findPrevious(int current, std::map<int, PreviousPkt> previousOne, int start)
{
    std::vector<int> previous;
    while (previousOne[current].previous != start)
    {
        previous.push_back(previousOne[current].previous);
        current = previousOne[current].previous;
    }
    return previous;
}

void outputDijkstra(std::map<int, std::vector<NextPt>>neighbors,int startingPt, std::map<int, PreviousPkt> previousOne,  std::string outputFile)
{
    std::vector<int> previousVector;
    bool isExisting = isExistingPt(neighbors, startingPt);
    std::ofstream file;
    file.open(outputFile, std::ofstream::app); // plik otworzy sie, nie nadpisze ale dopisze do pliku teskt
    if (isExisting)
    {
        file << "poszukiwanie najkrotszych drog z punktu: " << startingPt << std::endl;

    }
    else
    {
        file << "poszukiwanie najkrotszych drog z punktu: " << startingPt << std::endl;
        file << "Dany punkt nie istnieje w grafie!" << std::endl;
        return;
    }
    for (auto& previous : previousOne)
    {
        file << startingPt << "-> ";
        int id = previous.first;
        file << id;
        if (!previous.second.wasUsed)
        {
            file << "Do tego punktu nie da się dojść";
        }
        else
        {
            if (previous.second.previous == -1)
            {
                file << " wynosi 0 gdyz jest to punkt startowy";
            }
            else
            {
                file << " przez ";
                if (previous.second.previous == startingPt)
                {
                    file << previous.second.previous << ", wynosi: " << previous.second.distance;
                }
                else
                {
                    previousVector = findPrevious(previous.first, previousOne, startingPt);
                    for (int i = previousVector.size() - 1; i >= 0; i--)
                    {
                        file << previousVector[i];
                        if (previousVector.size() > 1 and i != 0)
                        {
                            file << " i ";
                        }
                    }
                    file << ", wynosi: " << previous.second.distance;
                }
            }

        }
        file << std::endl;
    }
    file.close();
    return;
}