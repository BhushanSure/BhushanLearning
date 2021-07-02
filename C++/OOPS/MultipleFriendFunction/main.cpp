#include <iostream>
#include <humidity.h>
#include <temperature.h>
using namespace std;

/*
 * A function can be a friend of more than one class at the same time.
 */

void printWeather(const Temperature &temperature, const Humidity &humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
                 " and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
    Humidity hum(10);
    Temperature temp(12);
    printWeather(temp, hum);
    return 0;
}
