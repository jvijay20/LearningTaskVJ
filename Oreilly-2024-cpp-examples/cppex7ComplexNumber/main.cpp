#include<iostream>
#include<cmath>
#include"Example7_ComplexNumber.h"
#include"Example7_ComplexNumber_Polar.h"
using namespace std;
ComplexNumber addTwoComplexNumbers(ComplexNumber& cart, ComplexNumber_Polar& polar)
{
    ComplexNumber result;
    result.setMemberVariables(cart.getRealPart() + polar.getMagnitude() * cos(polar.getAngle()), cart.getComplexPart() + polar.getMagnitude() * sin(polar.getAngle()));
    return result;
}
int main()
{
    ComplexNumber c, d;
    c.setMemberVariables(5, 3);
    cout << "Complex part = " << c.getComplexPart() << endl;
    c.print();
    d.setMemberVariables(5.3, 3.5);
    cout << "Complex part = " << d.getComplexPart() << endl;
    d.print();
    ComplexNumber e = c;
    e.print();
    ComplexNumber_Polar p;
    p.setMemberVariables(5, 3.14);
    ComplexNumber f = addTwoComplexNumbers(c, p);
    f.print();
    ComplexNumber *cDynamic = new ComplexNumber(10, 15);
    cDynamic->print();
    delete cDynamic;
    return 0;
}