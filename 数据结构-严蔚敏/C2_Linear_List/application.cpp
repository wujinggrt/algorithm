#include <iostream>
#include "LinearList.h"

using namespace std;

extern
Status visit(int e)
{
    std::cout << e << " ";
}

template <typename T>
Status equal(T l, T r)
{
    return l == r;
}

template <typename T>
void Union(SqList<T> &l, SqList<T> &r)
{
    auto l_len = l.ListLength();
    for (int i = 1; i <= r.ListLength(); ++i)
    {
        T e;
        r.GetElem(i, e);
        if (!l.LocateElem(e, equal))
        {
            l.ListInsert(++l_len, e);
        }// if
    }// for
}
// union

void RunUnion()
{
    SqList<int> l;
    SqList<int> r;
    l.ListInsert(1, 230);
    r.ListInsert(1, 22);
    Union(l, r);
    l.ListTraverse(visit);
    /*
    output:
    230 22
    */
}
// UnionTest

/*******************************
 * Union
*******************************/

// l, r都是有序的list，插入到dst中
template <typename T>
void MergeList(const SqList<T> &l, const SqList<T> &r, SqList<T> &dst)
{
    int i = 1; 
    int j = 1;
    int k = 0;
    while (i <= l.ListLength() && j <= r.ListLength())
    {
        T le;
        T re;
        l.GetElem(i, le);
        r.GetElem(j, re);
        if (le < re)
        {
            ++k;
            dst.ListInsert(k, le);
            ++i;
        }
        else
        {
            ++k;
            dst.ListInsert(k, re);
            ++j;
        }
    }
    while (i <= l.ListLength())
    {
        T e;
        l.GetElem(i, e);
        ++i;
        ++k;
        dst.ListInsert(k, e);
    }
    while (j <= r.ListLength())
    {
        T e;
        r.GetElem(j, e);
        ++j;
        ++k;
        dst.ListInsert(k, e);
    }
}
// MergeList

void RunMergeList()
{
    SqList<int> l, r, dst;
    l.ListInsert(1, 20);
    l.ListInsert(2, 220);
    l.ListInsert(3, 2304);
    l.ListTraverse(visit);
    cout << endl;
    r.ListInsert(1, 23);
    r.ListInsert(2, 205);
    r.ListInsert(3, 208);
    r.ListTraverse(visit);
    cout << endl;
    MergeList(l, r, dst);
    cout << endl;
    dst.ListTraverse(visit);
    cout << endl;
    /*
    output:
    20 220 2304
    23 205 208

    20 23 205 208 220 2304
    */
}
// RunMergeList

/*******************************
 * MergeList
*******************************/

int main()
{
    RunUnion();
    return 0;
}