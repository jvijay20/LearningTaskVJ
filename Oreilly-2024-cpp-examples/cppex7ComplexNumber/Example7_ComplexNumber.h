#include<iostream>
class ComplexNumber_Polar;
class ComplexNumber
{
    private:
    float realPart, complexPart;
    public:
    ComplexNumber();
    ComplexNumber(const ComplexNumber &c);
    ComplexNumber(const float &real, const float &complex);
    void setMemberVariables(float r, float c);
    float getRealPart();
    float getComplexPart();
    void print();
    friend ComplexNumber addTwoComplexNumbers(ComplexNumber& cart, ComplexNumber_Polar& polar);
};