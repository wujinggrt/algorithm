#include <ctime>

#include <iostream>
#include <queue>

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
    for (auto &e: v)
    {
        auto tmp = mpq.extract_min();
        cout << tmp << " ";
    }
    cout << endl;
    auto cmp = [](const int &lhs, const int &rhs) {return lhs > rhs;};
    priority_queue<int, std::vector<int>, decltype(cmp)> q(v.begin(), v.end(), cmp);
    for (auto &e: vector<char>(20))
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    /*
40 46 81 11 45 66 50 67 11 97 76 13 80 83 52 1 40 74 51 10
Print priority:
1 10 11 11 13 40 40 45 46 50 51 52 66 67 74 76 80 81 83 97
1 10 11 11 13 40 40 45 46 50 51 52 66 67 74 76 80 81 83 97
*/
    return 0;
}