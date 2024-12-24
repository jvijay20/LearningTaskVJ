#include<iostream>

class ComplexNumber
{
    private:
    float realPart, complexPart;
    public:
    ComplexNumber()
    {
        std::cout << "No arg-constructor called"<< std::endl;
    }
    ComplexNumber(const ComplexNumber &c)
    {
        realPart = c.realPart;
        complexPart = c.complexPart;
        std::cout << "Copy constructor called"<< std::endl; 
    }
    void setMemberVariables(float r, float c)
    {
        realPart = r;
        complexPart = c;
    }
    float getRealPart()
    {
        return realPart;
    }
    float getComplexPart()
    {
        return complexPart;
    }
    void print()
    {
        std::cout <<"real = " << realPart << " complex " << complexPart << std::endl;
    }
};

int main()
{
    ComplexNumber c, d;
    c.setMemberVariables(5, 3);
    std::cout << "Complex part = " << c.getComplexPart() << std::endl;
    c.print();
    d.setMemberVariables(5.3, 3.5);
    std::cout << "Complex part = " << d.getComplexPart() << std::endl;
    d.print();
    ComplexNumber e = c;
    e.print();
    return 0;
}