#include "deep.h"

/* As you can see, this is quite a bit more involved than a simple shallow copy! First, we have to
   check to make sure source even has a string (in below function at if (source.m_data)). If it does,
   then we allocate enough memory to hold a copy of that string (line 14). Finally, we have to manually
   copy the string (lines 17 and 18).
*/

void Deep::deepCopy(const Deep &source)
{
    // first we need to deallocate any value that this string is holding!
    if(!m_data)
        delete[] m_data;

    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;

    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source.m_data)
    {
        // allocate memory for our copy
        m_data = new char[m_length];

        // do the copy
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = nullptr;
}

// Copy constructor
Deep::Deep(const Deep &source)
{
    deepCopy(source);
}

/*Note that our assignment operator is very similar to our copy constructor, but there are three major differences:
    - We added a self-assignment check.
    - We return *this so we can chain the assignment operator.
    - We need to explicitly deallocate any value that the string is already holding
      (so we don’t have a memory leak when m_data is reallocated later).
*/
// Assignment operator
Deep &Deep::operator=(const Deep &source)
{
    // check for self-assignment
    if (this != &source)
    {
        // now do the deep copy
        deepCopy(source);
    }

    return *this;
}

Deep::~Deep()
{
    delete[] m_data;
}

Deep::Deep(const char *source)
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

char *Deep::getString()
{
    return m_data;
}

int Deep::getLength()
{
    return m_length;
}
