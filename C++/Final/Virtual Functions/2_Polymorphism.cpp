/*
    * Polymorphism :
    From the Greek Poly(many) and morph(forms). Polymorphism is the ability of objects to take on different forms or behave in
    different ways depending on the context in which they are used. In C++, polymorphism is primarily achieved through function
    (Like constructor) overloading and operator overloading. Function overloading allows us to define multiple functions with
    the same name but different parameter lists, enabling us to perform similar operations on different types of data.

    * Polymorphism are of two types:
    1. Compile-time polymorphism (also known as early binding or static polymorphism)
    2. Run-time polymorphism (also known as late binding or dynamic polymorphism).

    * Compile-time polymorphism :
    => Achieved by overloading functions and operators. Ex- Function Overloading, Constructor Overloading, Operator Overloading.
    * Function Overloading :
    It allows us to define multiple functions with the same name but different parameter lists, enabling us to perform similar operations on different types of data.
    * Operator Overloading : 
    It allows us to define custom behavior for operators when they are applied to user-defined types (classes). This enables us to use operators like +, -, *, etc.
    with objects of our classes, making the code more intuitive and readable. It works when we are defining multiple functions with the same name but different parameter lists.

    * Polymorphic class:
        A class having at least one virtual function is called a polymorphic class.In object-oriented programming, a polymorphic class is a class that can be used as a base 
        class for other derived classes, and can be accessed through a pointer or reference to its base class type. Polymorphic classes are typically designed with virtual 
        functions, which allow the derived classes to override the behavior of the base class functions.
 */

// Compile-time polymorphism example:

#include<bits/stdc++.h>
using namespace std;

class print {
    public:
    void show( int x) {
        cout << "int : " << x << endl;
    }

    void show(char ch){
        cout << "char : " << ch << endl;
    }

};
int main() {
    print p; // Create an object of the print class

    p.show(5); // Call the show function with an integer argument
    p.show('A'); // Call the show function with a character argument

    return 0;
}