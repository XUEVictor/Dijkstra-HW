#include "parser.h"
#include "GridGraph.h"

int mono::default_cost = 0;

int main(int argc, char **argv)
{
    cout << "############################################" << endl;
    cout << "#            Monotonic Routing             #" << endl;
    cout << "############################################" << endl;

    mono monotonic;
    /////////////////////parser/////////////////////
    monotonic.parser(argc, argv);
    cout << "............parser done!!!!!!.............." << endl;
    cout << "............parser done!!!!!!.............." << endl;

    GridGraph graph((monotonic.Bx2 + 1) * (monotonic.Bx2 + 1));
    graph.Getgridconncet(monotonic.NDcosts);
    // int size = monotonic.NDcosts.size();
    // for (int i = 0; i < size; i++)
    // {
    //     graph.UpdateCost(monotonic.NDcosts);
    // }
    ////////////////////////monotonic route///////////////////////

    graph.ShowAdjInfo(10);
    // std::vector<int> path;

    int S_Num = graph.Pos2Num(std::pair<int, int>(monotonic.sx, monotonic.sy));

    int E_Num = graph.Pos2Num(std::pair<int, int>(monotonic.tx, monotonic.ty));
    graph.Dijkstra(S_Num);
    std::pair<std::vector<int>, int> path;

    path = graph.GetPath(E_Num);
    for (std::vector<int>::iterator itr = path.first.begin(); itr != path.first.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }
    cout << "............monotonic routing done!!!!!!.............." << endl;
    /////////////////////output/////////////////////

    monotonic.output(argc, argv, path);
    cout << "............output done!!!!!!.............." << endl;

    return 0;
}
