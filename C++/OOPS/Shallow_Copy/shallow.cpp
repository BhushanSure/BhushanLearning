#include "shallow.h"

std::ostream& operator<<(std::ostream& out, const Shallow &f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

// A better implementation of operator=
Shallow& Shallow::operator= (const Shallow &fraction)
{
    // self-assignment guard
    if (this == &fraction)
        return *this;

    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}
