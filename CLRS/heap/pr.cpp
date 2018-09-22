#include <iostream>
#include <vector>
#include <ctime>

#include "./priority_queue.h"

using namespace std;

void print(vector<int> &v)
{
    for (auto &e: v)
        cout << e << " ";
    cout << endl;
}

int main()
{
    vector<int> v(20);
    srand(time(0));
    for (auto &e: v)
    {
        e = rand() % 100;
    }
    print(v);
    cout << "Print priority:" << endl;
    MinPriorityQueue<int> mpq(v);
    cout << __LINE__ << endl;
    for (auto &e: v)
    {
        auto tmp = mpq.extract_min();
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}