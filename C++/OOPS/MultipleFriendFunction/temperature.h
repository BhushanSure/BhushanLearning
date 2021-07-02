#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Humidity;
class Temperature
{
private:
    int m_temp;
public:
    Temperature(int temp=0);

    friend void printWeather(const Temperature &temperature, const Humidity &humidity);
};


#endif // TEMPERATURE_H
