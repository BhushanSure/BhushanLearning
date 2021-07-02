#include <iostream>
#include<empty.h>
#include<member.h>
#include<member_function.h>
using namespace std;

int main()
{
    Empty emp;
    member mem;
    member_function mem_func;

    std::cout<<sizeof (emp)<<"\n";
    std::cout<<sizeof (mem)<<"\n";
    std::cout<<sizeof (mem_func)<<"\n";
    return 0;
}
