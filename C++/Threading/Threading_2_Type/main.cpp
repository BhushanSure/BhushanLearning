#include <iostream>
#include <thread>
using namespace std;

// Function Pointer
void fun(int x)
{
    while(x-- > 0)
    {
        cout<< x << endl;
    }
}

// Functor and Non-Static member Function and Static member Function
class Base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
        {
            cout<<x<<endl;
        }
    }

    void run(int x)
    {
        while (x-- > 0)
        {
            cout<<x<<endl;
        }
    }

    static void runStatic(int x)
    {
        while (x-- > 0)
        {
            cout<<x<<endl;
        }
    }
};

int main()
{
    /************************************* Function Pointer ************************
    std::thread t(fun,10);
    t.join();
    ********************************************************************************/

    /************************************* Lambda Functions ************************
     * // We can directly inject lambda at thread creation time.
    auto fun = [](int x){
        while(x-- > 0)
        {
            cout<< x << endl;
        }
    };
    std::thread t(fun,10);
    t.join();
    ********************************************************************************/

    /************************************* Functor *********************************
    std::thread t((Base()),10);
    t.join();
    ********************************************************************************/

    /************************************* Non-Static member function **************
    Base b;
    std::thread t(&Base::run,&b,10);
    t.join();
    ********************************************************************************/

    /************************************* Static member function ******************
    std::thread t((&Base::runStatic),10);
    t.join();
    ********************************************************************************/

    return 0;
}
