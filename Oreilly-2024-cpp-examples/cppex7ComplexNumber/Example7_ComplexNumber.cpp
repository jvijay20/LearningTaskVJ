// Description: This file contains the defination of the ComplexNumber class
#include "Example7_ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
    std::cout << "No arg-constructor called"<< std::endl;
}
ComplexNumber::ComplexNumber(const ComplexNumber &c)
{
    realPart = c.realPart;
    complexPart = c.complexPart;
    std::cout << "Copy constructor called"<< std::endl; 
}
void ComplexNumber::setMemberVariables(float r, float c)
{
    realPart = r;
    complexPart = c;
}
float ComplexNumber::getRealPart()
{
    return realPart;
}
float ComplexNumber::getComplexPart()
{
    return complexPart;
}
void ComplexNumber::print()
{
    std::cout <<"real = " << realPart << " complex " << complexPart << std::endl;
}
