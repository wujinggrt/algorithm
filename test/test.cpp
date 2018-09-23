#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Hehe
{
public:
    Hehe(T t)
        : _i{t}
        {
            cout << "__ctor" << endl;
            cout << _i << endl;
        }
    
    T _i;
};

int main()
{
    Hehe h{20};
    Hehe hh(2);
    vector<int> vec{10};
    double d = 3.14;
    int i = {static_cast<int>(d)};
    int ii = {static_cast<int>(d)};
    cout << i << " " << d << endl;
    cout << vec.size() << endl;
    return 0;
}