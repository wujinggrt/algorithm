#include "graphs.h"

using namespace std;

template<typename Graph>
void graph_dfs(Graph &g);
template<typename Graph>
void graph_bfs(Graph &g);
template<typename Graph>
void graph_traverse(Graph &lg);

#define GRAPH_RUN(v, vec_arcs, method_call, param) do { \
    ListGraph<int> lg((v)); \
    printf("%s\n", "LstGraph"); \
    for (const auto &e: (vec_arcs)) \
    { \
        lg.set_edge(e); \
    } \
    lg.method_call(param); \
} while (0);

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

    GRAPH_RUN(v, vec_arcs, bfs, 0)
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
    GRAPH_RUN(v, vec_arcs, traverse, )
/*
0: 3 1
1: 4
2: 4 5
3: 1
4: 3
5: 5
*/
}

void testdfs()
{

    // CLRS p.632
    vector<Arc> vec_arcs_2{
        // a
        Arc{0, 1, 4}, Arc{0, 7, 8}, 
        // b
        Arc{1, 0, 4}, Arc{1, 7, 11}, Arc{1, 2, 8},
        // c
        Arc{2, 1, 8}, Arc{2, 3, 7}, Arc{2, 8, 2}, Arc{2, 5, 4},
        // d
        Arc{3, 2, 7}, Arc{3, 4, 9}, Arc{3, 5, 14},
        // e
        Arc{4, 3, 9}, Arc{4, 5, 10},
        // f
        Arc{5, 4, 10}, Arc{5, 3, 14}, Arc{5, 2, 4}, Arc{5, 6, 2},
        // g
        Arc{6, 5, 2}, Arc{6, 7, 1}, Arc{6, 8, 6},
        // h
        Arc{7, 6, 1}, Arc{7, 8, 7}, Arc{7, 0, 8}, Arc{7, 1, 11},
        // i
        Arc{8, 7, 7}, Arc{8, 6, 6}, Arc{8, 2, 2}
    };

    vector<int> v_2{0, 1, 2, 3, 4, 5, 6, 7, 8};

    GRAPH_RUN(v_2, vec_arcs_2, mst_kruskal, )
/*
{7, 6, 1}
{8, 2, 2}
{6, 5, 2}
{0, 1, 4}
{5, 2, 4}
{2, 3, 7}
{7, 0, 8}
{4, 3, 9}
*/
    GRAPH_RUN(v_2, vec_arcs_2, dfs, )
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

int main()
{
    test();

    return 0;
}