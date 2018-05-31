#include <iostream>
using namespace std;

template<typename T, typename U = string>
class Hehe
{
public:
    Hehe(T t, U u)
        : t_(t),
        u_(u)
    {}


    void Foo()
    {
        cout << t_ << " " << u_ << endl;
    }

private:
    T t_;
    U u_;
    
};

int main()
{
    Hehe<int, char*> h(1, {"ss"});
    h.Foo();
    return 0;
}