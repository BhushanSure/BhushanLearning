#include "classa.h"

//Default Constructor
ClassA::ClassA()
{

}

//Parametrized Constructor
ClassA::ClassA(const char *source, int id)
{
    _id = id;
    int m_length;
    m_length = std::strlen(source) + 1;

    // Allocate a buffer equal to this length
    _name = new char[m_length];

    // Copy the parameter string into our internal buffer
    for (int i{ 0 }; i < m_length; ++i)
        _name[i] = source[i];

    // Make sure the string is terminated
    _name[m_length-1] = '\0';

    std::cout<<"String:"<<_name<<"\n"<<"id:"<<_id;
}

//Destructor
ClassA::~ClassA()
{
    std::cout<<"Deleting Object"<<"\n";
    delete [] _name;
}

//Getter
char *ClassA::getString()
{
    return _name;
}

//Getter
int ClassA::getId()
{
    return _id;
}

//Setter
void ClassA::setString(const char *source)
{
    int m_length;
    m_length = std::strlen(source) + 1;

    // Allocate a buffer equal to this length
    _name = new char[m_length];

    // Copy the parameter string into our internal buffer
    for (int i{ 0 }; i < m_length; ++i)
        _name[i] = source[i];

    // Make sure the string is terminated
    _name[m_length-1] = '\0';
}

//Setter
void ClassA::setId(int id)
{
    _id = id;
}
