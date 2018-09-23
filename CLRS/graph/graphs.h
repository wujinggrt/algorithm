#ifndef GRAPHS_H__
#define GRAPHS_H__

#include <climits>
#include <cstdio>

#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

#define PRINTLN(v) std::cout << (v) << std::endl;
#define PRINTENTER std::cout << std::endl;
#define PRINT(v) std::cout << (v);
#define PRINT_LINE std::cout << __LINE__ << std::endl;
#define PRINT_FUNC std::cout << __func__ << std::endl;

template<typename T, typename Compare>
class PriorityQueue
{
public:
    template<typename It>
    PriorityQueue(It first, It last, Compare cmp)
        : v_(first, last),
        cmp_{cmp}
    {
        std::make_heap(v_.begin(), v_.end(), cmp_);
    }
    
    template<typename It>
    PriorityQueue(Compare cmp)
        : cmp_{cmp}
    {
        v_.reserve(10);
    }

    T top() const 
    {
        return v_[0];
    }

    void pop()
    {
        std::pop_heap(v_.begin(), v_.end(), cmp_);
        v_.pop_back();
    }

    size_t size() const
    {
        return v_.size();
    }

    bool empty() const 
    {
        return (size() ? false : true);
    }

    void push(const T &v)
    {
        v_.push_back(v);
        std::push_heap(v_.begin(), v_.end(), cmp_);
    }

    // if and only if compare successfully, it performs. The original one goes downwards.
    // if this is a min-priority queue, then cmp is greater,
    // src > dst, it works.
    bool change_val(const T &src, const T &dst)
    {
        if (!cmp_(src, dst))
        {
            return false;
        }
        int i = 0;
        for (; i < v_.size(); ++i)
        {
            if (v_[i] == src)
            {
                break;
            }
        }
        if (i == v_.size())
        {
            return false;
        }
        else
        {
            v_[i] = dst;
            if (i == 0)
            {
                return true;
            }
            for (int l = i / 2 - 1; l > 0; l = l / 2 - 1)
            {
                if (!cmp_(v_[l], v_[i]))
                {
                    return true;
                }
                std::swap(v_[l], v_[i]);
                i = l;
            }
            return true;
        }
    }
    
private:
    std::vector<T> v_;
    Compare cmp_;
};

/********************************************************* 
Forward declaration
*/

template<typename T>
class ListGraph;

template<typename T>
class MatrixGraph;

template<typename T>
void dfs(const ListGraph<T> &);

template<typename T>
void bfs(const ListGraph<T> &);

/********************************************************* 
Forward declaration
*/

// index of vertices.
struct Arc
{
    // tail -> head
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

/********************************************************* 
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

// friend void bfs(const ListGraph &g);
// friend void dfs(const ListGraph &g);
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
        auto arc_node = new ArcNode{arc.head, tmp, arc.weight};
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

#define PRINT_EDGE_WITH_WEIGHT(edges) \
        do { \
        for (auto &e: (edges)) \
        { \
            std::cout << "{" << e.tail << ", " << e.head << ", " << e.weight << "} " << "\n"; \
        } \
        std::cout << "\n"; \
        } while (0); 

    auto mst_kruskal()
    {
        std::vector<Arc> edges;
        edges.reserve(vertices_.size() * vertices_.size());
        for (int i = 0; i < vertices_.size(); ++i)
        {
            make_set(vertices_[i]);
            auto next = vertices_[i].next;
            while (next)
            {
                edges.push_back(Arc{i, next->i, next->weight});
                next=next->next;
            }
        }
        edges.shrink_to_fit();
        std::vector<Arc> result;
        result.reserve(edges.size());
        std::sort(edges.begin(), edges.end(), [](const Arc &lhs, const Arc &rhs){
            return lhs.weight < rhs.weight;
        });
        for (auto &e: edges)
        {
            if (find_set(vertices_[e.tail]) != find_set(vertices_[e.head]))
            {
                result.push_back(e);
                union_set(vertices_[e.tail], vertices_[e.head]);
            }
        }
        PRINT_EDGE_WITH_WEIGHT(result)
        return result;
    }

    // auto mst_prim(int r = 0)
    // {
    //     auto cmp = [&](VertexNode *lhs, VertexNode *rhs) {
    //         return lhs->d > rhs->d;
    //     };
    //     std::vector<VertexNode*>  pq;
    //     pq.reserve(vertices_.size() - 1);
    //     std::vector<bool> in_tree(vertices_.size(), false);
    //     for (int i = 0; i < vertices_.size(); ++i)
    //     {
    //         vertices_[i].d = INT_MAX;
    //         vertices_[i].parent = nullptr;

    //         if (i == r)
    //         {
    //             vertices_[r].d = 0;
    //         }
    //         pq.push_back(&vertices_[i]);
    //     }
    //     std::vector<Arc> result(vertices_.size() - 1, Arc{0, 0, INT_MAX});
    //     std::make_heap(pq.begin(), pq.end(), cmp);
    //     while (!pq.empty())
    //     {
    //         std::pop_heap(pq.begin(), pq.end(), cmp);
    //         auto u = pq.back();
    //         pq.pop_back();
    //         in_tree[u] = true;
    //         // 有限队列没有因为d的改变而维持
    //         // 需要自己实现了decresing的优先队列
    //         for (auto pv = vertices_[u].next; pv && pv->i != u; pv = pv->next)
    //         {
    //             auto v = pv->i;
    //             if (!in_tree[v] && pv->weight < vertices_[v].d)
    //             {
    //                 vertices_[v].parent = &vertices_[u];
    //                 vertices_[v].d = pv->weight;
    //                 if (vertices_[v].d < result[u].weight)
    //                 {
    //                     result[u] = Arc{u, v, pv->weight};
    //                 }
    //             }
    //         }
    //     }
    //     PRINT_EDGE_WITH_WEIGHT(result)
    //     return result;
    // }

    // after bfs.
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

// Disjoint set.
// Connected component.
private:
    void make_set(VertexNode &x)
    {
        x.parent = &x;
        x.d = 0;
    }

    void union_set(VertexNode &x, VertexNode &y)
    {
        link_nodes(find_set(x), find_set(y));
    }

    VertexNode* find_set(const VertexNode &v)
    {
        auto ret = v.parent;
        if (&v != v.parent)
        {
            ret = find_set(*v.parent);
        }
        return ret;
    }

    void link_nodes(VertexNode *x, VertexNode *y)
    {
        if (x->d > y->d)
        {
            y->parent = x;
        }
        else
        {
            x->parent = y;
            if (x->d == y->d)
            {
                ++(y->d);
            }
        }
    }

private:
    struct ArcNode
    {
        int i;
        ArcNode *next = nullptr;

        int weight = 0;
    };

    struct VertexNode
    {
        T v;
        ArcNode *next = nullptr;
        
        Color color = Color::White;
        // also for disjoint set operations as rank.
        int d = INT_MAX;
        VertexNode *parent = nullptr;

        int f = 0;
    };

    std::vector<VertexNode> vertices_;
};
/********************************************************* 
ListGraph
*/

/********************************************************* 
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
/********************************************************* 
MatrixGraph
*/ 

#endif