#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_next(const string &p)
{
    vector<int> next(p.size(), 0);
    // 为了好操作，设置为-1
    next[0] = -1;
    int i = 0;
    int j = -1;

    while (i < p.size())
    {
        /* 
        next中, 0: -1, 仅仅因为-1 + 1 = 0方便设为-1
        1: -1 + 1 = 0, 第一位不可能存在前后缀相等的情况，
        所以设为0，于是有效的部分是从next[2]开始比较。
        i = 1, j = 0. 
        比较的是前后缀，所以在i = j = 0的时候吗，没法进行，
        因此设置j = -1初始值
        */
       /*
        对于next的理解：假设有原字符串T， 匹配字符串P。
        next是PMT(Partial Match Table)右移一维的vector，除了第一位为-1。
        意义在于，对于next[j]，代表了在P的下标j的前一位，他的前后缀最大相同数量为next[j]。
        所以当P在j处于T不匹配的时候，调用j = next[j]，j就跳转到最大相同数量前缀的下一位（所以用next的名字吗？）。
        所以next[0] = -1，代表不合法，前一位无法比较。
        next[1] = 0, P的前一位只有一个字符，只可能取到0了。
        next[2]开始正常匹配。
       */
      // j = -1, 短路，不进行比较第二个next[j]
        if (j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            // 相同的前后缀cnt，回退
            j = next[j];
        }
    }

    return next;
}

void print_vec(const vector<int> &v)
{
    for (const auto &e: v)
    {
        cout << e << " ";
    }
    cout << endl;
}

template<typename T>
void print(T v)
{
    cout << v << endl;
}

auto kmp(const string &s, const string &p)
{
    auto next = get_next(p);
    int i = 0;
    int j = 0;
    while (i != s.size() && j != p.size())
    {
        // j = -1的情况为开头就不匹配。
        // 然后去else，取到-1,此时i没动，那么下一次if就驱使i、j前进
        // i->下一个, j->0，继续比较j的头
        if (j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            // i 不动， j 回退
            j = next[j];
        }
    }
    if (j == p.size())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

void test()
{
    string s = "ababababababababababababababababababcaHello world!";
    string p = "worl";
    auto i = kmp(s, p);
    cout << i << endl;
}

int main()
{
    test();
    return 0;
}