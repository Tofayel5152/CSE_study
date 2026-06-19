/*
    * Hybrid Inheritance :
        A combination of single, multiple, multilevel inheritance, hierarchical inheritance allowing for a more complex structure 
        where a derived class can inherit from multiple base classes and also serve as a base class for other derived classes.

        • Hybrid inheritance is also known as Virtual Inheritance. 
        • It is a combination of two or more inheritance. 
        • In hybrid inheritance, when derived class have multiple paths to a base class, a diamond problem occurs.It will result 
        in duplicate inherited members of the base class. 
        • To avoid this problem easily, we use Virtual Base Class (Next topic). In this case, derived classes should inherit base class by 
        using Virtual Inheritance.
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
        cout << "Roll Number: " << roll << endl; // Display the roll number specific to Student class
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
        cout << "Subject: " << subject << endl; // Display the subject specific to Teacher class
    }
};

// Derived class 3 inheriting from both Student and Teacher
class TA : public Student, public Teacher {
public:
    string department; // Extra member variable specific to TA class

    // Constructor for the derived class
    TA(string name, int age, int roll, string subject, string department)
        : Student(name, age, roll), Teacher(name, age, subject) {
        this->department = department; // Initialize the department
    }

    void display() {
        Student::display(); // Call the display method from Student class
        Teacher::display(); // Call the display method from Teacher class
        cout << "Department: " << department << endl; // Display the department specific to TAclass
    }
};

int main() {
    // Create an object of the derived class TeachingAssistant
    TA ta("Alice", 25, 202, "Computer Science", "Engineering");
    
    // Call the display method
    ta.display(); // This will display name, age, roll number, subject, and department

    return 0;
}