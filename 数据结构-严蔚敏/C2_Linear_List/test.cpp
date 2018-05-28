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
   auto p = make_shared<Hehe> ();
    return 0;
}