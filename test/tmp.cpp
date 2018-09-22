#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f(int i = 1)
{
	i = 5;
	cout << i << endl;
}

struct Hehe
{
	int _i = 0;
	char _c = 'a';
};

void func()
{
	struct A
	{
		int i_ = 1;
	};
	A a;
	cout << a.i_ << endl;
}

int main()
{
	int i = 109;
	auto &ri = i;
	ri = 9;
	cout << i << endl;
	return 0;
}
