#include <iostream>
#include <classa.h>
using namespace std;

int main()
{
    ClassA obj1("Hello World, Testing Started",2);
    std::cout<<"\n";
    std::cout<<obj1.getString()<<"\n"<<obj1.getId();
    std::cout<<"\n";
    obj1.setString("Bye Bye World");
    obj1.setId(5);
    std::cout<<obj1.getString()<<"\n"<<obj1.getId();
    std::cout<<"\n";
    return 0;
}
