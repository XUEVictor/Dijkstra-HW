#include "parser.h"
#define PAUSE                                     \
    {                                             \
        printf("Press Enter key to continue..."); \
        fgetc(stdin);                             \
    }

void mono ::parser(int argc, char **argv)
{
    //check argument count
    if (argc != 3)
    {
        cout << "Usage: ./mono <input_file_name> <output_file_name>" << endl;
        exit(1);
    }

    fstream fin;
    fin.open(argv[1], fstream::in);

    //check argument open
    if (!fin.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }

    char buffer[100];

    //parser start
    while (!fin.eof())
    {
        fin >> buffer;
        if (!strcmp(buffer, "BoundaryIndex"))
        {
            //input Bx1
            fin >> buffer;
            Bx1 = atoi(buffer);
            //input By1
            fin >> buffer;
            By1 = atoi(buffer);
            //input Bx2
            fin >> buffer;
            Bx2 = atoi(buffer);
            //input By2
            fin >> buffer;
            By2 = atoi(buffer);
        }
        if (!strcmp(buffer, "DefaultCost"))
        {
            //input default cost
            fin >> buffer;
            default_cost = atoi(buffer);
        }
        if (!strcmp(buffer, "NumNonDefaultCost"))
        {
            //set non default cost size
            fin >> buffer;
            int size = atoi(buffer);
            NDcosts.resize(size);

            for (int i = 0; i < size; ++i)
            {
                //input non default x1 y1 x2 y2 cost
                fin >> buffer;
                NDcosts[i].setX1(atoi(buffer));
                fin >> buffer;
                NDcosts[i].setY1(atoi(buffer));
                fin >> buffer;
                NDcosts[i].setX2(atoi(buffer));
                fin >> buffer;
                NDcosts[i].setY2(atoi(buffer));
                fin >> buffer;
                NDcosts[i].setValue(atoi(buffer));
            }
        }
        if (!strcmp(buffer, "Source"))
        {
            //input start x y
            fin >> buffer;
            sx = atoi(buffer);
            fin >> buffer;
            sy = atoi(buffer);
        }
        if (!strcmp(buffer, "Target"))
        {
            //input target x y
            fin >> buffer;
            tx = atoi(buffer);
            fin >> buffer;
            ty = atoi(buffer);
        }
    }

    fin.close();

    // The following demonstrates how to use the parser
    cout << "Boundary Index: " << Bx1 << " " << By1 << " " << Bx2 << " " << By2 << endl;
    cout << "Default cost: " << default_cost << endl;
    cout << "# non-default costs: " << NDcosts.size() << endl;
    for (int i = 0; i < NDcosts.size(); ++i)
    {
        cout << NDcosts[i].getX1() << " " << NDcosts[i].getY1() << " "
             << NDcosts[i].getX2() << " " << NDcosts[i].getY2() << " "
             << NDcosts[i].getValue() << endl;
    }

    return;
}

void mono ::routing(int argc, char **argv)
{
    //開啟dis 與 prev vector

    size = (Bx1 + 1) * (By1 + 1);

    Add_Connect(size);

    cal_cost(make_pair(sx, sy));

    Result_path = GetPath(make_pair(tx, ty));
}
void mono ::Add_Connect(int size)
{
    Adj.resize(Bx2 + 1);
    dis.resize(Bx2 + 1);
    prev.resize(Bx2 + 1);
    for (int i = 0; i < Bx2 + 1; i++)
    {
        Adj[i].resize(By2 + 1);
        dis[i].resize(By2 + 1);
        prev[i].resize(By2 + 1);
    }
    for (int x = 0; x <= Bx2; x++)
    {
        for (int y = 0; y <= By2; y++)
        {
            // std::cout<<x<<"  "<<y<<std::endl;
            if (x < Bx2)
            {
                AddConnection(std::pair<int, int>(x, y), std::pair<int, int>(x + 1, y), default_cost);
            }
            if (y < By2)
            {
                AddConnection(std::pair<int, int>(x, y), std::pair<int, int>(x, y + 1), default_cost);
            }
            dis[x][y] = INT_MAX;            //upper bound on the weight of a shortest path from s to v
            prev[x][y] = make_pair(-1, -1); //predecessor of v to be NULL
        }
    }
    UpdateCost_fix();
}
void mono ::AddConnection(std::pair<int, int> from, std::pair<int, int> to, int weight)
{
    //Add Connection , Adjacent vectrx
    //達到路徑上加上weight
    std::pair<std::pair<int, int>, int> V = std::make_pair(to, weight);
    Adj[from.first][from.second].push_back(V);
    std::cout << "( " << from.first << " , " << from.second << " ) "
              << "\tConnect to\t"
              << "( " << to.first << " , " << to.second << " ) "
              << " Cost : " << weight << std::endl;
}
void mono ::output(int argc, char **argv)
{
    fstream fout;
    fout.open(argv[2], fstream::out);

    if (!fout.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }
    fout << "RoutingCost " << Result_path.second << endl;
    fout << "RoutingPath " << Result_path.first.size() << endl;
    for (int i = Result_path.first.size() - 1; i >= 0; i--)
    {
        fout << Result_path.first[i].first << " " << Result_path.first[i].second << endl;
    }
    //////////////////////////////////////////////////////////
    //////////////////write your output///////////////////////
    //////////////////////////////////////////////////////////

    fout.close();

    return;
}

void mono::UpdateCost_fix()
{
    int cnt = 0;
    while (NDcosts.size() != 0)
    {
        // int St = Pos2Num(std::pair<int, int>(ND.back().getX1(), ND.back().getY1()));
        // int To = Pos2Num(std::pair<int, int>(ND.back().getX2(), ND.back().getY2()));
        int cost = NDcosts.back().getValue();
        for (std::list<std::pair<std::pair<int, int>, int>>::iterator itr = Adj[NDcosts.back().getX1()][NDcosts.back().getY1()].begin();
             itr != Adj[NDcosts.back().getX1()][NDcosts.back().getY1()].end(); itr++)
        {
            if ((*itr).first.first == NDcosts.back().getX2() && (*itr).first.second == NDcosts.back().getY2())
            {
                (*itr).second += cost;
                cout << "Update start \t" << NDcosts.back().getX1() << "," << NDcosts.back().getY1()
                     << "\tTo\t"
                     << NDcosts.back().getX2() << "," << NDcosts.back().getY2()
                     << "\tCost\t" << (*itr).second << std::endl;
                cnt++;
            }
        }
        NDcosts.pop_back();
    }

    std::cout << "=================================================" << std::endl;
    std::cout << "cnt : " << cnt << std::endl;
    std::cout << "=================================================" << std::endl;
    PAUSE;
}
void mono::Init(std::pair<int, int> start)
{
    dis[start.first][start.second] = 0;
}
void mono::cal_cost(std::pair<int, int> start)
{
    StartNode = start;
    Init(start);

    for (int x = 0; x <= Bx2; x++)
    {
        for (int y = 0; y <= By2; y++)
        {
            for (std::list<std::pair<std::pair<int, int>, int>>::iterator itr = Adj[x][y].begin(); itr != Adj[x][y].end(); itr++)
            {
                Relaxation(make_pair(x, y), make_pair((*itr).first.first, (*itr).first.second), (*itr).second);
                std::cout << "start  :" << x << "," << y << std::setw(8) << "To : " << (*itr).first.first << "," << (*itr).first.second
                          << std::setw(12) << "Distant : " << dis[(*itr).first.first][(*itr).first.second] << std::endl;
            }
        }
    }
}
void mono::Relaxation(std::pair<int, int> from, std::pair<int, int> to, int weight)
{

    if (dis[to.first][to.second] > dis[from.first][from.second] + weight)
    {
        dis[to.first][to.second] = dis[from.first][from.second] + weight;
        prev[to.first][to.second] = from;
    }
}

std::pair<std::vector<std::pair<int, int>>, int> mono::GetPath(std::pair<int, int> end)
{
    std::pair<std::vector<std::pair<int, int>>, int> result;
    int pathsize = 1;
    bool Done = false;
    std::vector<std::pair<int, int>> Path;
    std::pair<int, int> Ev = end;
    std::pair<int, int> Sv = make_pair(0, 0);
    //std::cout<<Ev<<std::endl;

    Path.push_back(Ev);
    std::cout << Ev.first << "," << Ev.second << std::endl;

    while (!Done)
    {
        Path.push_back(prev[Ev.first][Ev.second]);
        std::cout << prev[Ev.first][Ev.second].first << "," << prev[Ev.first][Ev.second].second << std::endl;
        if (prev[Ev.first][Ev.second] == StartNode || prev[Ev.first][Ev.second] == make_pair(-1, -1))
        {
            pathsize++;
            Done = true;
            break;
        }
        else
        {
            Ev = prev[Ev.first][Ev.second];
            pathsize++;
        }
    }
    Path.resize(pathsize);
    cout << "========================================" << endl;
    for (int i = 0; i < Path.size(); i++)
    {
        cout << Path[i].first << " " << Path[i].second << endl;
    }

    std::cout << "======================================" << std::endl;
    for (int i = Path.size() - 1; i >= 0; i--)
    {
        cout << Path[i].first << " " << Path[i].second << endl;
    }
    result.first = Path;
    result.second = dis[tx][ty];
    return result;
}