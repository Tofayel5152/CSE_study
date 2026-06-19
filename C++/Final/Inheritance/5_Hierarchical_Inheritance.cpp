/*
    * Hierarchial Inheritance: 
        Multiple base classes inherit from a single parent class, allowing for a shared base functionality while maintaining distinct child behaviors.
        Syntax: 
        class A { 
        // body of the class A. 
        }
        class B : public A { 
        // body of class B. 
        }
        class C : public A { 
        // body of class C. 
        }
        class D : public B {
        // body of class D. 
        }
*/
#include<bits/stdc++.h>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    // Constructor for the base class
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void display() {// Display method to show the name and age of the person in base class
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class 1
class Student : public Person {
public:
    int roll; // Extra member variable specific to Student class

    // Constructor for the derived class
    Student(string name, int age, int roll) : Person(name, age) { // Inherits name and age from Person class and roll as its own member variable
        this->roll = roll; // Initialize the roll number
    }

    void display() {
        Person::display(); // Call the base class display method that is inherited from Person class
        cout << "Roll Number: " << roll << endl;// Display the roll number specific to Student class
    }
};

// Derived class 2
class Teacher : public Person {
    public:
    string subject; // Extra member variable specific to Teacher class 

    // Constructor for the derived class
    Teacher(string name, int age, string subject) : Person(name, age) { // Inherits name and age from Person class and subject as its own member variable
        this->subject = subject; // Initialize the subject
    }

    void display() {
        Person::display(); // Call the base class display method that is inherited from Person class
        cout << "Subject: " << subject << endl;// Display the subject specific to Teacher class
    }
};

//Here we can add more derived classes like Admin, Staff, etc. that inherit from Person class but we should notice that each derived class has its own functionality and member variables while sharing the common properties of the base class Person. But not inter connected to each other.

int main() {
    // Create an object of the derived class Student
    Student student("John Doe", 20, 101);
    student.display(); // This will display name, age, and roll number

    // Create an object of the derived class Teacher
    Teacher teacher("Jane Smith", 35, "Mathematics");
    teacher.display(); // This will display name, age, and subject

    return 0;
}
