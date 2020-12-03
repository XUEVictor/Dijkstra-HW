#include "parser.h"

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

void mono ::routing()
{
    //////////////////////////////////////////////////////////
    ///////////////write your algorithm///////////////////////
    //////////////////////////////////////////////////////////

    return;
}

void mono ::output(int argc, char **argv, std::pair<std::vector<int>,int> array)
{
    fstream fout;

    fout.open(argv[2], fstream::out);

    if (!fout.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }

    //////////////////////////////////////////////////////////
    //////////////////write your output///////////////////////
    //////////////////////////////////////////////////////////

    std::pair<int, int> StartPos;
    std::pair<int, int> EndPos;
    fout << "RoutingCost "<< array.second << endl;
    fout << "RoutingPath "<< array.first.size() -1 << endl;

    for (int i = 1; i < array.first.size() - 1; i++)
    {
        StartPos = Num2Pos(array.first[i]);
        EndPos = Num2Pos(array.first[i + 1]);
        if (i == 1)
        {
            fout << StartPos.first << std::setw(4) << StartPos.second << endl;
        }

        fout << EndPos.first << std::setw(4) << EndPos.second << std::endl;
        // std::cout << StartPos.first << std::setw(4) << StartPos.second << std::setw(4)
        //           << EndPos.first << std::setw(4) << EndPos.second << std::endl;
    }

    fout.close();

    return;
}
std::pair<int, int> mono::Num2Pos(int Num)
{
    //std::cout<<Num<<std::endl;
    //std::cout<<GridLen<<std::endl;
    //std::cout<<(Num / GridLen)<<std::endl;
    int GridLen = this->Bx2 + 1;
    std::pair<int, int> Pos;
    Pos.first = Num / GridLen;
    //std::cout<<Pos.first<<std::setw(4);
    Pos.second = Num % GridLen;
    //std::cout<<Pos.second<<std::setw(4)<<std::endl;
    return Pos;
}