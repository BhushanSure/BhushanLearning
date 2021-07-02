#ifndef SHALLOW_H
#define SHALLOW_H

#include <iostream>
#include <cassert>

/*Shallow Copy :- Because C++ does not know much about your class, the default copy constructor and default assignment operators
it provides use a copying method known as a memberwise copy (also known as a shallow copy). This means that C++
copies each member of the class individually (using the assignment operator for overloaded operator=, and direct
initialization for the copy constructor). When classes are simple (e.g. do not contain any dynamically allocated memory),
this works very well.

The default copy constructor and assignment operator provided by the compiler for this class is defined in class.

Note that because these default versions work just fine for copying this class, there’s really no reason to write our
own version of these functions in this case.
However, when designing classes that handle dynamically allocated memory, memberwise (shallow) copying can get us in a
lot of trouble! This is because shallow copies of a pointer just copy the address of the pointer -- it does not allocate
any memory or copy the contents being pointed to!

Let’s take a look at an example of this:
*/

class Shallow
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor that compiler will provide, we have written here to just see how it will be internally
    // Same with Default Copy constructor and Default Assignment operator
    Shallow(int numerator=0, int denominator=1) : m_numerator{ numerator }, m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    // Default Copy constructor
    Shallow(const Shallow &f) : m_numerator{ f.m_numerator }, m_denominator{ f.m_denominator }
    {

    }

    //Default Assignment operator
    Shallow& operator= (const Shallow &fraction);

    //Overloaded << operator
    friend std::ostream& operator<<(std::ostream& out, const Shallow &f1);
};

#endif // SHALLOW_H
