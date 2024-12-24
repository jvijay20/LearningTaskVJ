#include"Example7_ComplexNumber_Polar.h"

using namespace std;

ComplexNumber_Polar::ComplexNumber_Polar()
{
    cout << "No arg-constructor called"<< endl;
}
ComplexNumber_Polar::ComplexNumber_Polar(const ComplexNumber_Polar &c)
{
    modulus = c.modulus;
    argument = c.argument;
    cout << "Copy constructor called"<< endl; 
}
void ComplexNumber_Polar::setMemberVariables(float m, float a)
{
    modulus = m;
    argument = a;
}
float ComplexNumber_Polar::getMagnitude()
{
    return modulus;
}
float ComplexNumber_Polar::getAngle()
{
    return argument;
}
void ComplexNumber_Polar::print()
{
    cout <<"modulus = " << modulus << " argument " << argument << endl;
}