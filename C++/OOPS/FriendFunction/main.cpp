#include <iostream>
#include<accumulator.h>
using namespace std;

// reset() is now a friend of the Accumulator class
void reset(Accumulator &accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
    std::cout<<"Friend Function access value: \t"<<accumulator.m_value<<"\n";
}

int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0
    return 0;
}
