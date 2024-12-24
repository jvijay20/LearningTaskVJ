#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char * studentName;

public:
    Student(const char* name)
    {
        cout << "Inside constructor: passed in string" << name << endl;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        cout << "name initialized to studentName: " << studentName << endl;
    }
    ~Student()
    {
        cout << "Inside destructor: deleting studentName" << endl;
        delete [] studentName;
    }
};

int main()
{
    Student s1("John");
    return 0;
}