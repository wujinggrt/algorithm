#ifndef TMP_H__
#define TMP_H__

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

#endif