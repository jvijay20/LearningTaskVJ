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

## Splitting Classes into multiple files
* So far, our examples have involved classes that are entirely "Defined" in just 1 file.
* so basically combines both the DECLARATION and DEFINITION of the member functions of the class into 1 file.
* But in Production code, classes will usually be split into 2 files,  there are simple ground rules to doing so.
 
 ### How are the Definition and Declaration different?
* Declaration of member functions - It is the signature.
    * It includes constructor.
    * It is placed in header file (.h).
    * It has no implementation.
* Definition of member functions - It is body.
    * It is placed in .cpp files.
    * It is source of the function declared.
    * The .cpp file must include .h file but not vice versa.
    * In .cpp file, refer to the functions of class using scope resolution operator.
    | for e.g for class ComplexNumber `ComplexNumber::ComplexNumber()` `ComplexNumber::ComplexNumber(double r, double c)`
    * Now any other file seeking to use your class should only INCLUDE #.hFile.
    * BTW, when you combine the definition and Declaration, the function become **INLINE**.
        * Theoritically, this could speed up the call to the function, especially if its a short one.
        * Every call to an inline function will be replaced by its body (by C++ Compiler).
        * we can make the function as INLINE function, using `inline` keyword if you wish.
    * Classes can have dependencies across them - and this can get complicated.
    * If class `A` references class `B` somewhere in some function signature, `A` has a dependency on `B`.
    * Typically you will just "Declare class `B` inside the header for class `A`". You will not include the header file for it.
    * This is a Forward Declaration.
    * If you have a Reference or Pointer to another class in your code, then you can Forward Declare.
    * If you have an Object of another class instantiated in your code, then you should #include the corresponding .h file.

## Setup a multi-file project with a dependency across objects
* Class 1: Complex number class (Cartesian coordinates)
    ```z = x + iy``` real(x), img(y)
* Class 2: Complex number class (Polar coordinates)
    ```z = r(cos t + i sin t)```, modulus(r), argument(t)
### Forward Declaration
* This is an important point - <span style="color:red"> Remember to add any forward declarations </span> <span style="color:blue">for types that are not #Included in your file </span>
* Think of this as a <span style="color:red">Placeholder class</span> compiler does not complain, you know that <span style="color:blue">
Real Class is going to be defined and declared elsewhere. </span>

## Dynamic Memory Allocation (DMA)
* We all have struggled with DMA in C

### Flashback to C
* `void *malloc (int num);` This a special function provided by the `stdlib.h` library in C to allow developers to manage memory.
    * A <span style="color:red">RETURN VALUE  `void*` </span> pointer indicates that the pointer can be to <span style="color:red">  ANY DATA TYPE. </span>
    * This can be <span style="color:red">  CAST </span>to the <span style="color:red">  TYPE OF POINTER </span>we are allocating memory for.
    * <span style="color:red">  NUMBER OF BYTES `(int num)` </span>, this specifies <span style="color:red">  HOW MUCH MEMORY </span> in bytes, we want to allocated.
    * `int* int_ptr = (int *)malloc(sizeof(int));`
    * `(int *)` here we allocate memory for an integer pointer, cast the return value to an <span style="color:red">  int* </span>.
    * `sizeof` can be used with <span style="color:red">  PRIMITIVES, STRUCTS and CONSTANTS </span> to figure out how much space each of them occupy.
* If you, as a developer allocate memory, then its your responsibility to <span style="color:red"> free it as well. </span> `void free (void *address);`
    * `free` returns nothing, simply frees up that portion of the memory for use by other portions of the program
    * It takes in an<span style="color:red">  void* </span>which means you can pass in a pointer to any data type.
* ```
    int* int_ptr = (int *)malloc(sizeof(int));
    int a = 34;
    ...
    free(int_ptr); // This frees the memory space that int_ptr used
    free(a); // This is wrong. You cannot free the integer a, you have not allocated memory for it.
    ```
## Stack memory and Heap memory
* In C there are 2 types of memory available to use.

|Stack Memory | Heap Memory |
|:---|:---|
| The CPU Manages the stack memory. <br>The <span style="color:red"> CPU</span> is responsible for allocating space in it and freeing up space as well| This portion of memory is managed by the <span style="color:red">DEVELOPER</span> writing code in C|
| Developers do not allocate or de-allocate space on the stack| The developer is responsible for allocating and freeing memory on the heap.|
|Memory allocated for variables which we just declare and use is on the STACK|Memory for pointers is allocated in the Heap region.|
|E.g<br>int a;<br>char c;<br>float f;<br>struct point3D;<br> <ul><li>The memory for all variables declared in this fashion are put on the stack managed by CPU.</li><li>It is called STACK because it behaves like a stack.</li>The stack grows and shrinks as functions push and pop local variables.<li>Newer variables go to the top of the stack.</li><li>Variables in the stack are managed by C <span style="color:red">AUTOMATICALLY.</li><li>Stack variables only exist so long as the function which created them is being executed.</span></li></ul>|<ul><li>The heap region of your computer's memory is <span style="color:red">not managed AUTOMATICALLY</span></li><li>The developer is responsible for managing memory using functions like `malloc()` and `free()`</li><li>If you fail to deallocate memory used on a Heap it results in a <span style="color:red">MEMORY LEAK.</span></li><li>Other ways to allocate memory `void *calloc(int num, int size)`</li><li>This is a special function which is useful to allocate memory for <span style="color:red">ARRAYS</span></li><li>This will allocate memory for NUM elements where each element is of SIZE bytes.</li><li>Say you have to allocate memory for a 100 integer elements in an ARRAY.<br>`int* arr = (int *)malloc(100 * sizeof(int));`<br>Is equivalent to:<br>`int * arr = (int *)calloc(100, sizeof(int));`</li><li>Resizing a block of memory<br>If you have already allocated some memory for an array, later you realise that you want to store additional elements.<br>`int* arr = (int *)malloc(100 * sizeof(int));`<br>Reallocation with increased size<br>`arr = (int *)realloc(arr, 200 * sizeof(int));`<br>The re-allocated memory block will start at the same address as the one originally allocated.<br>It will try to extend the block of memory from the end - which means <span style="color:red">ORIGINAL ELEMENTS</span> from the array will be <span style="color:red">PRESERVED.</span></li><li>What if memory is not available?<br>Each of these functions to allocate memory <span style="color:red">MALLOC(), CALLOC() and REALLOC()</span> will return a NULL POINTER if the memory is not avaialble.</li></ul>|
|Fast access.|Access is slower.|
|Space managed automatically and efficiently - does not get fragmented.|Managed by the developer and can get fragmented.|
|Variables are in the scope of the function declared..|Variables can be accessed anywhere in the program.(global access)|
|Smaller in size - has size limits.|Larger- typically limited by the memory on your computer.|

* We also just learnt about Objects, Classes, Constructors (which instantiates the onbject) and Destructors (which clean up the object before it ends).
* C++ Recap:

| Keywords | Summary |
|:--- |:--- |
| Classes |<ul><li>They are structs that contain functions</li><li>Often some variables and functions just make sense grouped together.</li><li>Some of these variables and functions might be interesting to the rest of the program, and these should be PUBLIC.<li>Others might be internal plumbing, and these should be PRIVATE.</li><li>This group of variables and functions is effectively a new, USER-DEFINED, TYPE.</li><li>Anyone can create a variable of this type.</li><li>Such a variable might require some intialisation and once its done, some clean-up</li><li>And coolest of all, other types can "Build on" this type.</li></ul>|

## Dynamic Memory Allocation
Remember 5 Rules:
* Never use `malloc/free` Again. Never.
* Use `new/delete` for single variables of all types.
* Use `new[]/delete[]` for array variables of all types.
* Corollary of rules 2 and rule3: Never mix `new/delete` and `new[]/delete[]`.
* Cleanup all pointer member variables in your destructor.

## Stop using malloc/free
__Rule#4__: Corollary of rules 2 and rule3: Never mix `new/delete` and `new[]/delete[]`.
* Anything you allocate + construct using <span style="color:red">new</span>, clean up using <span style="color:red">delete</span>.
* Anything you allocate + construct using <span style="color:red">new[]</span>, clean up using <span style="color:red">delete[]</span>.
* Destructos are crucial when your class has pointers or file handles among its member variables. In such cases, not freeing memory or closing files can lead to serious bugs - and memory and resource leaks.

## Stop using malloc/free
__Rule#1:__ Never use `malloc/free` again. Ever.
Why? Because `malloc/free` only assign memory. They don't call constructors and destructors.
Using them in C++ will have terrible terrible consequences.

### How this works
```
    ComplexNumber* cDynamic = (ComplexNumber*)malloc(sizeof(ComplexNumber));
    cout << "Printing out dynamically allocated object" << endl;
    cDynamic->print();

    free(cDynamic);
    cout <<"Okey-dokey! All done!" << endl;
```
* We run this code, and certain that no constructor is called.
* But in C++, we have cout statement to know which version of constructor has been called where as in malloc we are not having printf statement.
* Also we have some garbage values and does not intialise with constructor values.
* Rule#2: Use `new/delete` for single variables of all types.
* Anytime you need to create a single variable of a pointer type, just `new` to both `allocate and construct` the variable.
* You can use this with simple types (int/float etc) as well as object types.
```
    float* floatDynamic = new float(23.3);
    cout <<"Dynamically assigned float has value" = << *floatDynamic << endl;
    delete floatDynamic;
```
* You can pass in arguments  to the constructor when instantiating the pointer variables.
```
    ComplexNumber* cDynamic = new ComplexNumber(10,15);
    cout << "Printing out dynamically allocated object" << endl;
    cDynamic->print(); // This prints out all the member variables of the cDynamic.
    delete cDynamic;
```
* Rule#: Use `new[]/delete[]` for array variables of all types.
* Anything you allocate + construct using `new[]`, clean up using `delete[]`
* `new[]` will first allocate memory for the array and then call the default constructor for each array element. It will track array lenght too.
* `delete[]` will first call the destructor for each of array element, and deallocate the memory.
```
    ComplexNumber* cDynamic = new ComplexNumber[10];
    for(int i = 0; i<10; i++)
    {
        cout << "Printing out dynamically allocated object" << i<< endl;
        cDynamic[i].print(); // Notice how we use the DOT operator, not -> to refer to an individual element of this array.
    }
    delete cDynamic;
```
* Rule#4: Corollary of rules 2 and rule3: Never mix `new/delete` and `new[]/delete[]`.

## The Placement "new" operator
* This is a variation of `new`, which that ensures that an object resides at a specific memory location.
* Placement new takes in the memory location as a parameter.
* If you use placement `new`, you have to explicitly call the destructor.
* First setup a memory area using sizeof.
```
    int main()
    {
        char memoryBuffer[sizeof(ComplexNumber)]; //First setup a memory area using sizeof.
        // memoryBuffer holds the address of the object.
        void *place = (void*)memoryBuffer; //First setup a memory area using sizeof.
        // place is the variable that assigns the address which is void*

        ComplexNumber * cPlacedNew = new(place) ComplexNumber(10,5);
        cout << "Printing out dynamically allocated object that used placement new" << endl;
        cPlacedNew->~ComplexNumber();
        cout <<"Okey-dokey! All done" <<endl;
    }
```
* Dont use placement new under normal circumstances unless you absolutely have to (e.g in hardware applications).

## Understand "this" operator
* What is class?. A class is a struct that contains functions in addition to the data. Those functions will act on data, which forms a logical unit.
* What is object? A variable of the class is called an object (or instance of the class). 
* A class is the template or blueprint whereas the object is actual house or instance.
* Data items inside a class are called <span style="color:red">Member Variables</span> and functions inside a class are called <span style="color:red">Methods or Member Functions</span>.
* Every object has its own <span style="color:red">copies of the member variables </span>and the member functions of that object operate on those copies.
* Each object has a special pointer called `this`, which points to itself.
* `this` can be used inside any member function of an object to refer to itself, as if that object were any other variable.
* `this` comes to existence as soon as the object is created, stays in existence until the object is destructed.
```
    // Lets assume this member functions is part of Class ComplexNumber
    void printThis()
    {
        cout << "The address of the object is:" << this << endl; //holds address of the current object
        cout << "real part is: " << this->realPart << "imaginary part is: " << this->complexPart << endl; // access the varibles of current object.
    }
```
* The below code should actually print out the exact same address as the variable.
```
    cPlacedNew->printThis();
    cout << "Lets see if the address of our variables matches the address of `this`" << cPlacedNew << endl;
```
<li></li>
<span style="color:red">  void* </span>