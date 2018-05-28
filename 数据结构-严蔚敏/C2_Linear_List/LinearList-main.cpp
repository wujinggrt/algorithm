#include <iostream>
#include <vector>

#include "LinearList.h"

using namespace std;

Status visit(int e)
{
    cout << e << endl;
}

int main()
{
    SqList<int> l;
    cout << (l.ListEmpty()) << endl;
    l.ListInsert(1, 2);
    cout << (l.ListEmpty()) << endl;
    cout << l.ListLength() << endl;
    l.ListInsert(2, 10);
    l.ListInsert(3, 23);
    l.ListInsert(4, 432);
    int i;
    l.GetElem(2, i);
    cout << i << endl;
    l.PriorElem(10, i);
    cout << i << endl;
    l.NextElem(10, i);
    cout << i << endl;
    l.ListTraverse(visit);
    return 0;
}