#ifndef GRAPHS_H__
#define GRAPHS_H__

// index of vertices.
struct Arc
{
    int tail = 0;
    int head = 0;
    int weight = 1;
};

/* 
ListGraph
*/

auto print_graph = [](auto e){
        std::cout << e.v << ": ";
        auto next = e.next;
        while (next) {
            std::cout << next->i << " ";
            next = next->next;
        }
        std::cout << std::endl;
    };

template<typename T>
class ListGraph
{
public:
    template<typename Iter>
    ListGraph(Iter first, Iter end)
        : vertices_(end - first)
    {
        for (auto &e: vertices_)
        {
            e.v = *first;
            ++first;
        }
    }

    ListGraph(const std::vector<T> &v)
        : ListGraph(v.begin(), v.end())
    {}

    void set_edge(Arc arc)
    {
        auto tmp = vertices_[arc.tail].next;
        auto arc_node = new ArcNode{arc.head, tmp};
        vertices_[arc.tail].next = arc_node;
    }
    // set_edge

    template<typename Callabel = decltype(print_graph)>
    void traverse(Callabel c = print_graph)
    {
        for (const auto &e: vertices_)
        {
            c(e);
        }
    }
    // taverse

private:
    struct ArcNode
    {
        int i;
        ArcNode *next = nullptr;
    };

    struct VertexNode
    {
        T v;
        ArcNode *next = nullptr;
    };

    std::vector<VertexNode> vertices_;
};
/* 
ListGraph
*/

/* 
MatrxGraph
*/

template<typename T>
class MatrixGraph
{
public:
    template<typename Iter>
    MatrixGraph(Iter first, Iter end)
        : vertices_(first, end),
        arcs_(vertices_.size(), std::vector<int>(vertices_.size(), 0))
    {
    }

    MatrixGraph(const std::vector<T> &v)
        : MatrixGraph(v.begin(), v.end())
    {}
    // ctor

    void set_edge(Arc arc)
    {
        arcs_[arc.tail][arc.head] = arc.weight;
    }
    // set_edge

    void traverse()
    {
        for (auto &e: arcs_)
        {
            for (auto &ae: e)
            {
                std::cout << ae << " ";
            }
            std::cout << std::endl;
        }
    }
    // taverse

private:
    std::vector<T> vertices_;
    std::vector<std::vector<int>> arcs_;
};
/* 
MatrixGraph
*/ 


#endif