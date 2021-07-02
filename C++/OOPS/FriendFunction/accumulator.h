#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H
#include<iostream>

/*
 * A friend function is a function that can access the private members of a class as though it were a
 * member of that class. In all other regards, the friend function is just like a normal function.
 * A friend function may be either a normal function, or a member function of another class. To declare
 * a friend function, simply use the friend keyword in front of the prototype of the function you wish to
 * be a friend of the class. It does not matter whether you declare the friend function in the private or
 * public section of the class.
*/

class Accumulator
{
private:
    int m_value;
public:
    Accumulator();
    void add(int value);

    // Make the reset() function a friend of this class
    friend void reset(Accumulator &accumulator);
};

#endif // ACCUMULATOR_H
