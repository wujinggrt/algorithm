#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f(int i = 1)
{
	i = 5;
	cout << i << endl;
}

int main()
{
	vector<int> v{1, 2, 3, 4};
	std::swap(v[1], v[2]);
	for (auto &e: v)
		cout << e << endl;
	f();
	return 0;
}
