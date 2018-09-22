#include <iostream>
#include <string>
using namespace std;

auto naive_matching(const string &t, const string &p)
{
    auto n = t.size();
    auto m = p.size();
    // 如果找不到，返回t的下一个位置，即是end
    decltype(n) ret = n - m;
    for (decltype(n) s = 0; s < n - m; ++s)
    {
        for (decltype(n) st = 0; st < p.size(); ++st)
        {
            if (p[st] != t[st + s])
            {
                break;
            }
            if (st == p.size() - 1)
            {
                ret = s;
            }
        }
        if (ret != n - m)
        {
            break;
        }
    }
    return ret;
}

int main()
{
    string s = "ababababababababababababababababababcaHello world!";
    string p = "worl";
    cout << naive_matching(s, p) << endl;
    return 0;
}