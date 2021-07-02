#ifndef DEEP_H
#define DEEP_H

#include <iostream>
#include <cassert>
#include <cstring>

/*
One answer to shallow copy problem in case of dynamically allocated variable is to do a deep copy
on any non-null pointers being copied. A deep copy allocates memory for the copy and then copies
the actual value, so that the copy lives in distinct memory from the source. This way, the copy
and source are distinct and will not affect each other in any way. Doing deep copies requires that
we write our own copy constructors and overloaded assignment operators.
*/


class Deep
{
private:
    char *m_data;
    int m_length;
public:
    void deepCopy(const Deep& source);

    // Copy constructor
    Deep(const Deep& source);

    // Assignment operator
    Deep& operator=(const Deep & source);

    // destructor
    ~Deep();

    //Constructor
    Deep(const char *source = "");

    char *getString();
    int getLength();
};

#endif // DEEP_H
