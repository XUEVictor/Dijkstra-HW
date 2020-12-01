#include "GridGraph.h"
void GridGraph::PrintDataArray(std::vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
        std::cout << std::setw(4) << i;
    std::cout << std::endl;
    for (int i = 0; i < array.size(); i++)
        std::cout << std::setw(4) << array[i];
    std::cout << std::endl;
}
//初始化
void GridGraph::Initialize(int Start)
{
    //開啟足夠vector, 不然會出錯
    dis.resize(V_num);
    pi.resize(V_num);
    for (int i = 0; i < V_num; i++)
    {
        dis[i] = Max_Dis; //upper bound on the weight of a shortest path from s to v
        //pi[i] = NULL;
        pi[i] = -1; //predecessor of v to be NULL
    }
    //initialize the first distant index to 0
    dis[Start] = 0;
}

void GridGraph::Relaxation(int from, int to, int weight)
{

    if (dis[to] > dis[from] + weight)
    {
        dis[to] = dis[from] + weight;
        pi[to] = from;
    }
}

void GridGraph::AddConnection(int from, int to, int weight)
{
    //Add Connection , Adjacent vectrx
    //達到路徑上加上weight
    std::pair<int, int> V = std::make_pair(to, weight);
    Adj[from].push_back(V);
}

void GridGraph::Dijkstra(int Start)
{
    StartVectex = Start;
    Initialize(Start);

    //create a V_num of Queue
    Heap h;
    h.makeHeap(dis);

    while (!h.isEmpty())
    {
        bool open = false;

        //int u = minQueue.ExtractMin();
        int u = h.extractMin();
        //std::cout<<u<<std::endl;
        //SysStop();
        /*
        if(u==1){
            std::cout<<"Enter"<<std::endl;
            open = true;
        }
        */

        for (std::list<std::pair<int, int>>::iterator itr = Adj[u].begin(); itr != Adj[u].end(); itr++)
        {
            //form adjacent to Relaxation min dis
            Relaxation(u, (*itr).first, (*itr).second);
            if (open)
            {
                std::cout << u << std::setw(8) << (*itr).first << std::setw(8) << (*itr).second << std::endl;
            }
            // std::cout<<(*itr).first<<std::setw(4)<<dis[(*itr).first]<<std::endl;
            //updete tree when it change
            h.chgkey((*itr).first, dis[(*itr).first]);
            std::cout<<"start  :"<<u<<std::setw(8)<<"To : "<<(*itr).first<<std::setw(12)<<"Distant : "<<dis[(*itr).first]<<std::endl;
        }
    }
}

void GridGraph::ShowData(std::vector<int> array)
{
    // fout << array.size() - 1 << std::endl;
    std::cout << array.size() - 1 << std::endl;
    for (int i = 0; i < array.size() - 1; i++)
    {
        std::pair<int, int> StartPos;
        std::pair<int, int> EndPos;
        StartPos = Num2Pos(array[i]);
        EndPos = Num2Pos(array[i + 1]);
        // fout << StartPos.first << std::setw(4) << StartPos.second << std::setw(4)
        //  << EndPos.first << std::setw(4) << EndPos.second << std::endl;
        std::cout << StartPos.first << std::setw(4) << StartPos.second << std::setw(4)
                  << EndPos.first << std::setw(4) << EndPos.second << std::endl;
    }
}

void GridGraph::ShowAdjInfo(int idx)
{

    std::cout << "Size = " << Adj[idx].size() << std::endl;
    //first = to
    //second = value
    for (std::list<std::pair<int, int>>::iterator itr = Adj[idx].begin(); itr != Adj[idx].end(); itr++)
    {
        std::cout << (*itr).first << std::setw(4) << (*itr).second << std::endl;
    }
    //SysStop();
}

std::vector<int> GridGraph::GetPath(int end)
{
    int size = 1;
    bool Done = false;
    std::vector<int> Path;
    int Ev = end;
    int Sv = 0;
    //std::cout<<Ev<<std::endl;
    Path.push_back(Ev);
    while (!Done)
    {
        Path.push_back(pi[Ev]);
        //std::cout<<pi[Ev]<<std::endl;
        if (pi[Ev] == StartVectex || pi[Ev] == -1)
        {
            size++;
            Done = true;
            break;
        }
        else
        {
            Ev = pi[Ev];
            size++;
        }
    }
    Path.resize(size);

    std::reverse(Path.begin(), Path.end());
    ShowData(Path);
    return Path;
}

std::pair<int, int> GridGraph::Num2Pos(int Num)
{
    //std::cout<<Num<<std::endl;
    //std::cout<<GridLen<<std::endl;
    //std::cout<<(Num / GridLen)<<std::endl;
    std::pair<int, int> Pos;
    Pos.first = Num / GridLen;
    //std::cout<<Pos.first<<std::setw(4);
    Pos.second = Num % GridLen;
    //std::cout<<Pos.second<<std::setw(4)<<std::endl;
    return Pos;
}

int GridGraph::Pos2Num(std::pair<int, int> pos)
{
    // cout<<"--------------------------"<<endl;
    // cout<<"pos.first : "<<pos.first<<endl;
    // cout<<"GridLen : "<<GridLen<<endl;
    // cout<<"pos.second : "<<pos.second<<endl;
    // cout<<"--------------------------"<<endl;

    return pos.first * GridLen + pos.second;
}

void GridGraph::UpdateCost(std::vector<int> path)
{
    //PrintDataArray(path);
    for (int i = 0; i < path.size() - 1; i++)
    {
        int start = path[i];
        int End = path[i + 1];
        for (std::list<std::pair<int, int>>::iterator itr = Adj[start].begin(); itr != Adj[start].end(); itr++)
        {

            if ((*itr).first == End)
            {
                (*itr).second += 10;
                //start to end add cost
                if ((*itr).second > 10 * capacity)
                {
                    (*itr).second += 10000;
                    //std::cout<<"Close th path : " <<start<<std::setw(4)<<End<<std::endl;
                    ++ClosePathCnt;
                }
                //end to start add cost
                //std::cout<<"Update : "<<start<<std::setw(4)<<End<<std::setw(4)<<"    Cost : "<<(*itr).second<<std::endl;
                break;
            }
        }
        for (std::list<std::pair<int, int>>::iterator itr = Adj[End].begin(); itr != Adj[End].end(); itr++)
        {

            if ((*itr).first == start)
            {
                (*itr).second += 10;
                //start to end add cost
                if ((*itr).second > 10 * capacity)
                {
                    (*itr).second += 10000;
                    //std::cout<<"Close th path : " <<start<<std::setw(4)<<End<<std::endl;
                    ++ClosePathCnt;
                }
                //end to start add cost
                //std::cout<<"Update : "<<End<<std::setw(4)<<start<<std::setw(4)<<"    Cost : "<<(*itr).second<<std::endl;
                break;
            }
        }
        //ShowAdjInfo(start);
        //std::cout<<std::endl;
    }
}

void GridGraph::GetCap(int Cap)
{
    //std::cout<<Cap<<std::endl;
    capacity = Cap;
}

void GridGraph::CheckOverFlow()
{

    for (int i = 0; i < Adj.size(); i++)
    {
        for (std::list<std::pair<int, int>>::iterator itr = Adj[i].begin(); itr != Adj[i].end(); itr++)
        {

            if ((*itr).second > 10000 * 2)
            {
                std::cout << "--------------------------------------------------------------------------------" << std::endl;
                std::cout << "Start " << i << " to " << (*itr).first << " overflow Weight : " << (*itr).second << std::endl;
                std::cout << "--------------------------------------------------------------------------------" << std::endl;
            }

            //std::cout<<"Start "<<i<<" to "<<(*itr).first<<" Weight : "<<(*itr).second<<std::endl;
        }
    }
}

void GridGraph::Getgridconncet(std::vector<NDcost> ND)
{
    int edg_limit = sqrt(V_num);
    int Max = edg_limit * edg_limit;

    std::pair<std::pair<int, int>, int> Top_cost = UpdateCost(ND);

    for (int i = 0; i < Max; ++i)
    {
        if (i + 1 < Max)
        {
            //check is it a edge of grid
            if ((i + 1) % edg_limit)
            {
                int extra_cost = 0;

                if (Top_cost.first.first == i && Top_cost.first.second == i + 1)
                {
                    extra_cost = Top_cost.second;
                    // cout << Top_cost.first.first << " " << Top_cost.first.second << " "
                    //      << Top_cost.second << endl;
                    Top_cost = UpdateCost(ND);

                }
                this->AddConnection(i, i + 1, mono::default_cost + extra_cost);

                std::pair<int, int> pos_start = Num2Pos(i);
                std::pair<int, int> pos_end = Num2Pos(i + 1);
                // std::cout << "i :\t" << i << "\t connect to " << i + 1 << std::endl;
                // std::cout << "(" << pos_start.first << "," << pos_start.second << ")" << std::endl;
                // std::cout << "(" << pos_end.first << "," << pos_end.second << ")" << std::endl;
                // std::cout << "Cost : " << mono::default_cost + extra_cost << std::endl;
                // std::cout << "=================================================" << std::endl;
            }
            //i have a neighbor and cost is init 1
            //------------------------------------
            if (i + edg_limit < Max)
            {
                int extra_cost = 0;

                if (Top_cost.first.first == i && Top_cost.first.second == i + edg_limit)
                {
                    extra_cost = Top_cost.second;
                    // cout << Top_cost.first.first << " " << Top_cost.first.second << " "
                    //      << Top_cost.second << endl;
                    Top_cost = UpdateCost(ND);

                }
                this->AddConnection(i, i + edg_limit, mono::default_cost + extra_cost);

                std::pair<int, int> pos_start = Num2Pos(i);
                std::pair<int, int> pos_end = Num2Pos(i + edg_limit);
                // std::cout << "i :\t" << i << "\t connect to " << i + edg_limit << std::endl;
                // std::cout << "(" << pos_start.first << "," << pos_start.second << ")" << std::endl;
                // std::cout << "(" << pos_end.first << "," << pos_end.second << ")" << std::endl;
                // std::cout << "Cost : " << mono::default_cost + extra_cost << std::endl;
                // std::cout << "=================================================" << std::endl;
            }
        }
    }
}

std::pair<std::pair<int, int>, int> GridGraph::UpdateCost(std::vector<NDcost> &ND)
{
    if (ND.size() > 0)
    {

        // cout << ND.back().getX1() << " " << ND.back().getY1() << " "
        //      << ND.back().getX2() << " " << ND.back().getY2() << " "
        //      << ND.back().getValue() << endl;
        // cout << "GridLen : " << GridLen<<std::endl;

        std::pair<int, int> start2end;
        start2end.first = Pos2Num(std::pair<int, int>(ND.back().getX1(), ND.back().getY1()));
        start2end.second = Pos2Num(std::pair<int, int>(ND.back().getX2(), ND.back().getY2()));
        // std::cout << "Start :\t" << start2end.first << "\t to " << start2end.second << std::endl;
        std::pair<int, int> pos_start = Num2Pos(start2end.first);
        std::pair<int, int> pos_end = Num2Pos(start2end.second);
        // std::cout << "(" << pos_start.first << "," << pos_start.second << ")" << std::endl;
        // std::cout << "(" << pos_end.first << "," << pos_end.second << ")" << std::endl;
        int cost = ND.back().getValue();
        // std::cout << "cost : " << cost << std::endl;
        ND.pop_back();
        return std::pair<std::pair<int, int>, int>(start2end, cost);
    }
    else
    {
        // std::cout << "NULL" << std::endl;

        return std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 0), 0);
    }
}