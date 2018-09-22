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

int main()
{
	cout << (Hehe{1, 'c'})._i << endl;
	return 0;
}
