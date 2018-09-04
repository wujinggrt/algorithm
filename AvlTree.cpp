#include <utility>
#include <iostream>
using namespace std;

template<typename Comparable>
struct AvlNode 
{
    Comparable element;
    AvlNode *left = nullptr;
    AvlNode *right = nullptr;
    int height;

    AvlNode(const Comparable &e, AvlNode *l, AvlNode *r, int h = 0)
        : element{e},
        left{l},
        right{r}
    {
    }

    AvlNode(Comparable &&e, AvlNode *l, AvlNode *r, int h = 0)
        : element{std::move(e)},
        left{l},
        right{r}
    { 
    }

    int height(AvlNode *t) const 
    {
        return t == nullptr ? -1 : t->height;
    }
};

void insert(AvlNode *&t, const Comparable &t)
{

}