#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef long long int  ull;

void Loop_1(ull start, ull end)
{
    for(ull i = start; i<=end ; i++)
    {

    }
}

void Loop_2(ull start, ull end)
{
    for(ull i = start; i<=end ; i++)
    {

    }
}

int main()
{
    ull start = 0, end = 1900000000;
    auto startTime = high_resolution_clock::now();

    /* //WITHOUT THREAD
    Loop_1(start,end);
    Loop_2(start,end);
    */

    //WITH THREAD
    std::thread t1(Loop_1, start, end);
    std::thread t2(Loop_2, start, end);
    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "Sec: " << duration.count()/1000000 << endl;
    return 0;
}
