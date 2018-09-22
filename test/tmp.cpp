#include <iostream>
using namespace std;

int main()
{
	int i = 10;
	int *p = &i;
	cout << sizeof(i) << endl;
	cout << sizeof(p) <<endl;
	return 0;
}
