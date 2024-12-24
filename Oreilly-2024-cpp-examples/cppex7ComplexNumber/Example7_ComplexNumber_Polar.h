#include<cmath>
#include<iostream>

class ComplexNumber_Polar{
    private:
    float modulus, argument;
    public:
    ComplexNumber_Polar();
    ComplexNumber_Polar(const ComplexNumber_Polar &c);
    void setMemberVariables(float m, float a);
    float getMagnitude();
    float getAngle();
    void print();
};