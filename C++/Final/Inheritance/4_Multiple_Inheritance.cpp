/*
    * Multiple Inheritance : 
        Provides a way for a derived class to inherit from multiple base classes, allowing it to combine the functionalities of those base classes.
        Caution: This can lead to complex relationships and potential ambiguity, especially when multiple base classes have members with the same name.

        Syntax:
        class subclass_name : access_mode <base_class1>, access_mode <base_class2>, .... {
        // body of subclass
        };

        * Ambiguity problem in Multiple Inheritance:
        When Two base classes have functions with the same name, while a class derived from both base classes. How do objects of the derived class access the 
        correct base class function ? The name of the function alone is insufficient, since the compiler can’t figure out which of the two functions is meant.
        => The problem is resolved using the scope-resolution operator to specify the class in which the function lies.
        
        Solution:
            #include <bits/stdc++.h>
            using namespace std;

            class A {
                public:
                    void show() { cout << "Class A\n"; }
            };

            class B {
                public:
                    void show() { cout << "Class B\n"; }
            };

            class C : public A, public B {
                // No need to define show() here, as it is inherited from both A and B
            };

            int main() {
                C objC; // object of class C
                * // objC.show(); // ambiguous--will not compile
                objC.A::show(); // OK
                objC.B::show(); // OK
                return 0;
            }   

*/

#include<bits/stdc++.h>
using namespace std;

// Base class 1
class Student {
public:
    string name;
    int roll;

    Student(string name, int roll) {
        this->name = name;
        this->roll = roll;
    }

};

// Base class 2
class Teacher {
public:
    string subject;
    double salary;

    Teacher(string subject, double salary) {
        this->subject = subject;
        this->salary = salary;
    }
};

// Derived class inheriting from both Student and Teacher
class TA : public Student, public Teacher {
public:
    string department;// Extra member variable specific to TA class

    // Constructor for the derived class
    TA(string name, int roll, string subject, double salary, string department) : Student(name, roll), Teacher(subject, salary) {
        this->department = department;
        }

    void display() {
        cout << "Name: " << name << ", Roll: " << roll << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Create an object of the derived class
    TA ta1("Alice", 101, "Computer Science", 50000, "Engineering");

    // Call the display method
    ta1.display(); // This will display name, roll number, subject, department, and salary.

    return 0;
}