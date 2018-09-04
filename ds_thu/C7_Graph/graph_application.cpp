#include <iostream>
#include <vector>

#include "Graph.h"

using namespace std;

int main()
{
    MatrixGraph<string> mg;
    mg.CreateGraph();
    mg.Print();
    return 0;
}