#ifndef GRAPHS_H__
#define GRAPHS_H__

#include <climits>
#include <cstdio>

#include <vector>
#include <iostream>
#include <queue>
#include <string>

#define PRINTLN(v) std::cout << (v) << std::endl;
#define PRINTENTER std::cout << std::endl;
#define PRINT(v) std::cout << (v);
#define PRINT_LINE std::cout << __LINE__ << std::endl;
#define PRINT_FUNC std::cout << __func__ << std::endl;

// index of vertices.
struct Arc
{
    int tail = 0;
    int head = 0;
    int weight = 1;
};

enum class Color
{
    White,
    Gray,
    Black
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

auto print_visited = [] (auto u) {
    std::cout << "visited:" << u.v << std::endl;
};

template<typename T>
class ListGraph
{
struct ArcNode;
struct VertexNode;

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

    // input the index of vertices.
    template<typename Callable = decltype(print_visited)>
    void bfs(int start, Callable call = print_visited)
    {
        for (auto &u: vertices_)
        {
            u.color = Color::White;
            u.d = INT_MAX;
            u.parent = nullptr;
        }
        auto s = &(vertices_[start]);
        s->color = Color::Gray;
        s->d = 0;
        s->parent = nullptr;
        std::queue<VertexNode*> q;
        q.push(s);
        while (!q.empty())
        {
            auto &u = q.front();
            q.pop();
            std::cout <<"ready to visit:";
            for (auto arc = u->next; arc; arc = arc->next)
            {
                auto v = &vertices_[arc->i];
                if (v->color == Color::White)
                {
                    v->color = Color::Gray;
                    v->d = u->d + 1;
                    v->parent = u;
                    q.push(v);
                    std::cout << v->v << " ";
                }
            }
            std::cout << std::endl;
            call(*u);
            u->color = Color::Black;
        }
    }

    template<typename Callable = decltype(print_visited)>
    void dfs(Callable call = print_visited)
    {
        for (auto &u: vertices_)
        {
            u.color = Color::White;
            u.parent = nullptr;
        }
        auto time = 0;
        for (auto &u: vertices_)
        {
            [&u](){
                PRINTLN((u.v))
                PRINTENTER
            }();
            if (u.color == Color::White)
            {
                dfs_visit(u, time, call);
            }
        }
    }

    void print_path(int s, int v)
    {
        // exception
        if (v < 0 || v >= vertices_.size())
        {
            std::cout << "err" << std::endl;
            return;
        }
        // base case.
        if (v == s)
        {
            std::cout << s << " ";
        }
        else if (!vertices_[v].parent)
        {
            std::cout << "no path!!!" << std::endl;
            return;
        }
        else
        {
            print_path(s, find(vertices_[v].parent->v));
            std::cout << v << " ";
        }
    }

private:
    int find(const T &v)
    {
        for (int i = 0; i < vertices_.size(); ++i)
        {
            if (vertices_[i].v == v)
            {
                return i;
            }
        }
        return -1;
    }

    template<typename Callable = decltype(print_visited)>
    void dfs_visit(VertexNode &u, int &time, Callable call = print_visited)
    {
        ++time;
        u.d = time;
        u.color = Color::Gray;
        for (auto arc = u.next; arc; arc = arc->next)
        {
            auto &v = vertices_[arc->i];
            if (v.color == Color::White)
            {
                v.parent = &u;
                dfs_visit(v, time, call);
            }
        }
        call(u);
        u.color = Color::Black;
        ++time;
        u.f = time;
    }

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
        
        Color color = Color::White;
        int d = INT_MAX;
        VertexNode *parent = nullptr;

        int f = 0;
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