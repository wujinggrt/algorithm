#include <iostream>
using namespace std;

template<typename T> class FriendTest;

template<typename T>
void print(const FriendTest<T> &h, int i);

template<typename T>
class FriendTest
{
    friend void print<T>(const FriendTest<T> &, int);
public:
    FriendTest(T i = 0)
        : i_{i}
    {}

private:
    int i_;
};


template<typename T>
void print(const FriendTest<T> &h, int i)
{
    std::cout << h.i_ << "\n";
    std::cout << i << "\n";
}

int main()
{
	FriendTest<int> f(100);
	print(f, 2);
	return 0;
}