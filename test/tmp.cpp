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

auto func()
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
	func();
	return 0;
}
