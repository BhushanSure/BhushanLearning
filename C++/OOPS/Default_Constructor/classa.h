#ifndef CLASSA_H
#define CLASSA_H
#include <iostream>
#include <cstring>

/*Constructor :- A constructor is a special kind of class member function that is automatically
               called when an object of that class is instantiated. Constructors are typically
               used to initialize member variables of the class to appropriate default or user-provided
               values. Constructors must have the same name as the class (with the same capitalization) .
               Constructors have no return type (not even void) . Many new programmers are confused about
               whether constructors create the objects or not. They do not -- the compiler sets up the memory
               allocation for the object prior to the constructor call. Constructors actually serve two purposes.
               First, constructors determine who is allowed to create an object. That is, an object of a class can
               only be created if a matching constructor can be found. Second, constructors can be used to initialize
               objects. Whether the constructor actually does an initialization is up to the programmer. It’s
               syntactically valid to have a constructor that does no initialization at all (the constructor still
               serves the purpose of allowing the object to be created, as per the above).*/

/*Default Constructor :- A constructor that takes no parameters (or has parameters that all have default values)
                         is called a default constructor. The default constructor is called if no user-provided
                         initialization values are provided.*/

class ClassA
{
private:
    int _id;
    char *_name;
public:
    ClassA();
    ClassA(const char *source, int id);
    ~ClassA();

    char* getString();
    int getId();

    void setString(const char *source);
    void setId(int id);
};

#endif // CLASSA_H
