#include <iostream>
#include <vector>
using namespace std;

class Hehe
{
public:
    Hehe(int i = 0)
        : _i{i}
        {
            cout << "__ctor" << endl;
            cout << _i << endl;
        }
    
    int _i;
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