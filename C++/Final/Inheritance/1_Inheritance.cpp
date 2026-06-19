/*
    * What is Inheritance? 
        • Provides a way to create a new class from an existing class 
        • The new class is a specialized version of the existing class 
    => Inheritance is a fundamental concept in object-oriented programming that allows a class(Child,Derived class) to inherit properties
    and behaviors (methods) from another class(Parent,Base class). This promotes code reuseability and establishes a natural hierarchy between classes.

    * The "is a" Relationship 
        • Inheritance establishes an "is a" relationship between classes. 
        – A car is a vehicle 
        – A flower is a plant 
        – A football player is an athlete 
        • An object of a derived class 'is an' object of the base class
        – an UnderGrad is a Student 
        – a Mammal is an Animal
        • Notation: 
        class Student // base class 
        { 
        . . . 
        }; 
        class UnderGrad : public student 
        { // derived class 
        . . . 
        }; 
        • A derived object has all of the characteristics of the base class

    * What Does a Child Have? 
        An object of the derived class has: 
        • all members defined in child class 
        • all members declared in parent class 

        An object of the derived class can use: 
        • all public members defined in child class 
        • all public members defined in parent class 

    * Mode of Inheritance:( class Student : public Person{...} here public is the mode of inheritance )
        1. Public Inheritance: The public members of the base class remain public in the derived class, and protected members remain protected.
        2. Protected Inheritance: The public and protected members of the base class become protected in the derived class.
        3. Private Inheritance: The public and protected members of the base class become private in the derived class.

        * The private members of the base class are not accessible in the derived class, regardless of the inheritance mode. *

    * Types of Inheritance:
        1. Single Inheritance: A derived class inherits from a single base class.
        2. Multi-level Inheritance: A derived class inherits from another derived class.
        3. Multiple Inheritance: A derived class inherits from multiple base classes.
        4. Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
        5. Hybrid Inheritance: A combination of two or more types of inheritance, such as multiple and multilevel inheritance.

*/

#include<bits/stdc++.h>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    // Constructor for the base class
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class
class Student : public Person { // ":" is used to specify that Student is inheriting from Person class and "public" is the mode of inheritance
public:
    int roll ;//extra member variable specific to Student class

    // Constructor for the derived class
    Student(string name, int age, int roll) : Person(name, age) { //inherits name and age from Person class and roll as its own member variable
        // Initialize the roll number
        // You can also use this->name = name; and this->age=age; but the constructor is already initializing the base class members and its not necessary 
        //to do it again
        this->roll = roll;
    }

    void display() {
        Person::display();// Call the base class display method that is inherited from Person class
        // '::' is the scope resolution operator used to specify that we want to call the display method from the Person class, which is the base class of Student.
        cout << "Roll Number: " << roll << endl;
    }
};

int main() {
    // Create an object of the derived class
    Student student("John Doe", 20, 101);
    
    // Call the display method
    student.display(); // This will display name, age, and roll number

    return 0;
}