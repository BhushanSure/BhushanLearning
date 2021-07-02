#include <iostream>
#include <shallow.h>
using namespace std;

/*While this code looks harmless enough, it contains an insidious problem that will cause
the program to crash! Can you spot it? Don’t worry if you can’t, it’s rather subtle.

shallow copy{ hello } <--- This line below seems harmless enough as well, but it’s actually
the source of our problem! When this line is evaluated, C++ will use the default copy constructor
(because we haven’t provided our own). This copy constructor will do a shallow copy, initializing
copy.m_data to the same address of hello.m_data. As a result, copy.m_data and hello.m_data are now
both pointing to the same piece of memory!

When copy goes out of scope, the shallow destructor is called on copy. The destructor deletes
the dynamically allocated memory that both copy.m_data and hello.m_data are pointing to! Consequently,
by deleting copy, we’ve also (inadvertently) affected hello. Variable copy then gets destroyed, but hello.m_data
is left pointing to the deleted (invalid) memory!

So, std::cout << hello.getString() << '\n'; <---- this line will give undefined behaviour.

Now you can see why this program has undefined behavior. We deleted the string that hello was
pointing to, and now we are trying to print the value of memory that is no longer allocated.

The root of this problem is the shallow copy done by the copy constructor -- doing a shallow copy
on pointer values in a copy constructor or overloaded assignment operator is almost always asking for trouble.
*/



int main()
{
    shallow hello{ "Hello, world!" };
    cout << hello.getString() << '\n';

    {
        shallow copy{ hello }; // use default copy constructor
    } // copy is a local variable, so it gets destroyed here.
      // The destructor deletes copy's string, which leaves hello with a dangling pointer.

    cout << hello.getString() << '\n'; // this will have undefined behavior

    return 0;
}
