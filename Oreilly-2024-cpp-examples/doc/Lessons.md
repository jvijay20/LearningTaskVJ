# Oreilly 
Link: learn-by-example<https://learning.oreilly.com/videos/learn-by-example/9781789137774/9781789137774-video4_1/>

## Using namespace std 
* indicates that we want to use functions and variables from the namespace std 

## Function overloading
* each overloaded version has a different signature: number, order and type of func parameters 
* Func cant be overloaded based on return type 
* Programers can also specify DEFAULT VALUES for func parameters 

## References
* Used to change the value of arguments passed to functions without using pointers
* No memory allocation, no memory leaks or even nulls (a ref can never be a NULL) 
* CONST – keyword to prevent unwanted or inadvertent modifications (avoid using DEFINE instead use const variable) 

## C++ vs C 
* Objects vs Structs 
* New/Delete vs Malloc/Free 
* String vs Char*  

## CLASS
* some  of  variables and funcs makes sense to group together, others might be internal plumbing and used as private. 
* Some of variables  and funcs might be interesting to rest of world/prog and these should be public. 
* Anyone can create variable of this type. This user defined type is called CLASS and it corresponds exactly to STRUCT in C. 
* The variable created of class is called object of (instance of) Class. 
* Class contains member variables and member functions or methods. 

### Constructor
* (same name as class) member function to take care of taking these in and assinging to corresponding member variables.

### Destructor
* (~ sign)member func to take care of cleaning up the object just before it ceases to exist.

Programs: /media/jvijay20/Ubuntu/Oreilly/Oreilly-2024-cpp-examples 

## Ex:1 - Define a simple C++ class 

* Lets create a simple class to hold a Complex Number (real and imaginary parts) 
* So when constructor doesnt initialise the member variables, then garbage values will be set. 
* So we could avoid this garbage values initialisation once we intialise member variables in the constructor. 

    After constructor function() : realPart(0.0), imgPart(0.0) 

    Delimited by colon and before start of curly braces along with initialisation of variables 

* Destructor (~) is a special member function that cleans up member variables of an object. 
    It cleans up the memory of member variables 

## Access Modifiers
* Member func and member variables can be marked as PUBLIC (If usable outside of the class) 
* Member func and member variables can be marked as PRIVATE (If usable internal to the class) 

* C++ uses the COPY CONSTRUCTOR to create (Copy) one object from ANOTHER 
* We are accessing the private member variables of the another instance of the object 
* This constructor has same name as Class name with argument passing same datatype and assign the private member variables of the class  
* Access Modifiers exist to Force Good design not for Security 
* In General, only make PUBLIC what you must – By default Keep everything PRIVATE 
* Keep All Member variables PRIVATE – ALWAYS – Provide Public Getter/Setter methods for those variables 

     

     

 

 