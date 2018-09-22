#include "graphs.h"

using namespace std;

template<typename Graph>
void graph_dfs(Graph &g);
template<typename Graph>
void graph_bfs(Graph &g);
template<typename Graph>
void graph_traverse(Graph &lg);

template<typename Vertex, typename Arc>
void list_graph(Vertex &v, Arc &vec_arcs)
{
        
    ListGraph<int> lg(v);
    printf("%s\n", "LstGraph");
    for (const auto &e: vec_arcs)
    {
        lg.set_edge(e);
    }
    graph_dfs(lg);
}

template<typename Graph>
void graph_dfs(Graph &lg)
{
    lg.dfs();
/*
LstGraph
0

visited:4
visited:1
visited:3
visited:0
1

2

visited:5
visited:2
3

4

5

*/
}

template<typename Graph>
void graph_bfs(Graph &lg)
{
    lg.bfs(0);
/*
ready to visit:3 1
visited:0
ready to visit:
visited:3
ready to visit:4
visited:1
ready to visit:
visited:4
*/
    lg.print_path(0, 4);
    cout << endl;
/*
0 1 4
*/
}

template<typename Graph>
void graph_traverse(Graph &lg)
{
    lg.traverse();
/*
0: 3 1
1: 4
2: 4 5
3: 1
4: 3
5: 5
*/
}

template<typename Vertex, typename Arc>
void matrix_graph(Vertex &v, Arc &vec_arcs)
{
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
}

void test()
{
    vector<Arc> vec_arcs{
        Arc{0, 1}, Arc{0, 3},
        Arc{1, 4},
        Arc{2, 5}, Arc{2, 4},
        Arc{3, 1},
        Arc{4, 3},
        Arc{5, 5}};
    vector<int> v{0, 1, 2, 3, 4, 5};

    list_graph(v, vec_arcs);
}

int main()
{
    test();

    return 0;
}