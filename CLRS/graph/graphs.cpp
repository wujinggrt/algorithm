#include <cstdio>
#include "graphs.h"

using namespace std;

#define PRINT_LINE std::cout << __LINE__ << std::endl;

int main()
{
    vector<Arc> vec_arcs{
        Arc{0, 1}, Arc{0, 3},
        Arc{1, 4},
        Arc{2, 5}, Arc{2, 4},
        Arc{3, 1},
        Arc{4, 3},
        Arc{5, 5}};
    vector<int> v{0, 1, 2, 3, 4, 5};
    ListGraph<int> lg(v);
    printf("%s\n", "LstGraph");
    for (const auto &e: vec_arcs)
    {
        lg.set_edge(e);
    }
    lg.traverse();
/*
0: 3 1
1: 4
2: 4 5
3: 1
4: 3
5: 5
*/
    printf("%s\n", "MatrixGraph");
    MatrixGraph<int> mg(v);
    for (auto &e: vec_arcs)
    {
        mg.set_edge(e);
    }
    mg.traverse();
/*
MatrixGraph
0 1 0 1 0 0
0 0 0 0 1 0
0 0 0 0 1 1
0 1 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 1
*/


    return 0;
}