#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "tmp.h"
#include "atest.h"

template<typename T>
void print(const FriendTest<T> &h, int i)
{
    std::cout << h.i_ << "\n";
    std::cout << i << "\n";
}

void f(int i = 1)
{
	i = 5;
	cout << i << endl;
}

struct Hehe
{
	int _i = 0;
	char _c = 'a';

	Hehe(vector<int> &v)
	{
		cout << __LINE__ << endl;
	}
};

auto func()
{
	struct A
	{
		int i_ = 1;
	};
	cout << (A{(4)}).i_ << endl;
}

#define PRINT_V(v) \
	for (auto &e: (v))\
	{\
		cout << e << " ";\
	}\
	cout << '\n';

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
	PRINT_V(v)
	auto cmp = [](int lhs, int rhs){
		return lhs > rhs;
	};
	pop_heap(v.begin(), v.end(), cmp);
	PRINT_V(v)
	
	return 0;
}