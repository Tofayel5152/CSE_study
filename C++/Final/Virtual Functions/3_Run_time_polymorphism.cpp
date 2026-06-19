/*
    * Run time polymorphism :
    It is achieved through virtual functions and inheritance. It allows us to call derived class methods through base class pointers or references,
    enabling dynamic binding at runtime. This means that the method that gets executed is determined at runtime based on the actual object type,
    rather than the type of the pointer or reference. It works in runtime, and it also known as dynamic polymorphism. Example of Run time polymorphism
    is  function overriding.
    
    * Function overriding : 
    Overriding is dependent on inheritance, where a derived class provides a specific implementation of a function that is already defined in its 
    base class. This allows the derived class to modify or extend the behavior of the base class function. Parent & Child both contain the same 
    function with different implementation.The parent class function is said to be overridden. The name and elements of those functions will be 
    same but the implementation will be different because it will depend on the which class (Object) is called.

*/

#include<bits/stdc++.h>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function enables runtime polymorphism
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }
    
    // Virtual destructor is good practice
    virtual ~Shape() {}
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle." << endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square." << endl;
    }
};

int main() {
    // Pointer to base class
    Shape* shapePtr;
    
    Circle circleObj;
    Square squareObj;

    // Point to Circle
    shapePtr = &circleObj;
    shapePtr->draw(); // Output: Drawing a Circle. (Resolved at runtime)

    // Point to Square
    shapePtr = &squareObj;
    shapePtr->draw(); // Output: Drawing a Square. (Resolved at runtime)

    return 0;
}   

/*
    * Overloading vs. Overriding 
    • Overloading 
        – single method name having several alternative implementations. 
    • Overriding 
        – child class provides alternative implementation for parent class method. 
*/