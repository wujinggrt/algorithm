#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned long ul = 0xFFFFFFFFFFFFFFFF; // 16个F， 16^16-1
	int si = -1;
	cout << ul << endl;
	cout << "si==ul:" << (ul == si) << endl;
	return 0;
}
