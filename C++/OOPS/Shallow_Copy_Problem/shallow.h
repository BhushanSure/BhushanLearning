#ifndef SHALLOW_H
#define SHALLOW_H

#include<iostream>
#include<cstring>
#include<cassert>

/*The below is a simple string class that allocates memory to hold a string that we pass in.
Note that we have not defined a copy constructor or overloaded assignment operator. Consequently,
C++ will provide a default copy constructor and default assignment operator that do a shallow copy.
The copy constructor will look something like this:

shallow::shallow(const shallow &source) : m_length{ source.m_length }, m_data{ source.m_data }
{

}

Note that m_data is just a shallow pointer copy of source.m_data, meaning they now both point to the same thing.
Both means first object's m_data and second object's m_data as Second object is copy of First object.
Look above constructor parameter line i.e., m_data{ source.m_data }

*/

class shallow
{
private:
    char *m_data;
    int m_length;
public:
    shallow(const char *source = "");
    ~shallow(); // destructor
    char *getString();
    int getLength();
};

#endif // SHALLOW_H
