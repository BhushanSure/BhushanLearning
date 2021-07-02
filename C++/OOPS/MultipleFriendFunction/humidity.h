#ifndef HUMIDITY_H
#define HUMIDITY_H

class Temperature;
class Humidity
{
private:
    int m_humidity;
public:
    Humidity(int humidity=0);

    friend void printWeather(const Temperature &temperature, const Humidity &humidity);
};

#endif // HUMIDITY_H
