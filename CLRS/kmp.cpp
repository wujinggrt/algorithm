#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto get_next(const string &p)
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
        if (j == -1 || p[i] == next[j])
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

 