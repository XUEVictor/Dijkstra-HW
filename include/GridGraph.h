#include <vector>
#include <list>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>

#include "heap.h"
#include "parser.h"

class GridGraph
{
private:
    std::vector<std::list<std::pair<int, int> > > Adj;
    int V_num;
    int StartVectex;
    int GridLen;
    int capacity;
    std::vector<int> pi, dis;
    const int Max_Dis = INT_MAX;
    int ClosePathCnt = 0;
public:
    GridGraph(int n) : V_num(n)
    {
        Adj.resize(V_num);
        GridLen = sqrt(V_num);
        //std::cout<<GridLen<<std::endl;
    }
    std::pair<std::vector<int>,int> GetPath(int end);
    void AddConnection(int from, int to, int weight);
    void ShowAdjInfo(int idx);
    void ShowData(std::vector<int> array);
    void PrintDataArray(std::vector<int> array);
    void Initialize(int Start);
    void Relaxation(int X, int Y, int weight);
    void Dijkstra(int Start = 0);
    std::pair<int, int> Num2Pos(int Num); // Return Grid position
    int Pos2Num(std::pair<int, int> Pos); // Return num position
    void UpdateCost_fix(std::vector<NDcost> &ND);
    void Getgridconncet(std::vector<NDcost> ND);
    std::pair<std::pair<int, int>,int> UpdateCost(std::vector<NDcost>& ND);
    
};