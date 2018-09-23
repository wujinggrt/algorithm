#include <iostream>
#include <string>
#include <vector>
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

int main()
{
	FriendTest<int> f(100);
	print(f, 2);
	return 0;
}