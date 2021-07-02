#include <iostream>
#include <deep.h>
using namespace std;

int main()
{
    Deep hello{ "Hello, world!" };
    cout << hello.getString() << '\n';

    {
        Deep copy{ hello };
    }

    cout << hello.getString() << '\n'; // this will not have undefined behavior

    return 0;
}
