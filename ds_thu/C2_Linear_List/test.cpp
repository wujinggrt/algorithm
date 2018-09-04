#include <iostream>
#include <memory>

using namespace std;

class Hehe
{
    public:
    ~Hehe()
    {
        cout << "dtor" << endl;
    }
};

int main()
{
    cout << INT_MAX << endl;
    return 0;
}