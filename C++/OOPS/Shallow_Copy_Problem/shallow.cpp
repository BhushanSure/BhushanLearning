#include "shallow.h"

shallow::shallow(const char *source)
{
    assert(source); // make sure source isn't a null string

    // Find the length of the string
    // Plus one character for a terminator
    m_length = std::strlen(source) + 1;

    // Allocate a buffer equal to this length
    m_data = new char[m_length];

    // Copy the parameter string into our internal buffer
    for(int i{0}; i<m_length; i++)
    {
        m_data[i] = source[i];
    }

    // Make sure the string is terminated
    m_data[m_length - 1] = '\0';
}

shallow::~shallow()
{
    delete[] m_data;
}

char *shallow::getString()
{
    return m_data;
}

int shallow::getLength()
{
    return m_length;
}
