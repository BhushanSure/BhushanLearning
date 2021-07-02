#include "accumulator.h"

Accumulator::Accumulator():m_value{0}
{

}

void Accumulator::add(int value)
{
    m_value += value;
    std::cout<<"value: \t"<<m_value<<"\n";
}
