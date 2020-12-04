#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <list>
#include <climits>
#include <algorithm>

using namespace std;

class NDcost
{
public:
    //////////////////set////////////////////
    void setX1(int x1) { _x1 = x1; }
    void setY1(int y1) { _y1 = y1; }
    void setX2(int x2) { _x2 = x2; }
    void setY2(int y2) { _y2 = y2; }
    void setValue(int value) { _value = value; }

    //////////////////get////////////////////
    int getX1() { return _x1; }
    int getY1() { return _y1; }
    int getX2() { return _x2; }
    int getY2() { return _y2; }
    int getValue() { return _value; }

private:
    int _x1;
    int _y1;
    int _x2;
    int _y2;
    int _value;
};

class mono
{
public:
    /////////////////////////////functions/////////////////////////////

    void parser(int argc, char **argv);
    void routing(int argc, char **argv);
    void output(int argc, char **argv);
    void Add_Connect(int size);
    void UpdateCost_fix();
    void AddConnection(std::pair<int, int> from, std::pair<int, int> to, int weight);
    void Init(std::pair<int, int> start);
    void cal_cost(std::pair<int, int> start);
    void Relaxation(std::pair<int, int> from, std::pair<int, int> to, int weight);
    std::pair<std::vector<std::pair<int, int>>, int> GetPath(std::pair<int, int> end);

    /////////////////////////////declaration/////////////////////////////

    //boundary x1 y1 x2 y2
    int Bx1;
    int By1;
    int Bx2;
    int By2;

    //default cost
    int default_cost;
    int size;
    //non default cost
    vector<NDcost> NDcosts;
    std::vector<std::vector<int>> dis;                  //存放node cost
    std::vector<std::vector<std::pair<int, int>>> prev; //存放座標
    std::vector<std::vector<std::list<std::pair<std::pair<int, int>, int>>>> Adj;
    std::pair<int, int> StartNode = make_pair(-1, -1);
    std::pair<std::vector<std::pair<int, int>>, int> Result_path;
    
    //start x y;
    int sx;
    int sy;

    //target x y;
    int tx;
    int ty;

    const int int_max = INT_MAX;
};

#endif // PARSER_H
