/* 
    * Multi-level inheritance: 
        Parent to Child to Grandchild (Like "Parent to Child" and than that Child act as a Parent  and than again "parent to child",
        but now the parent is mainly that child and the child is a grandchild of main parent)
        Syntax:- 
        class C { Parent class
        //body of class C 
        };
        class B : public C { Child class
        //body of class B 
        };
        class A : public B { Grandchild class
        //body of class A 
        };

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
};

// Derived class
class Student : public Person {
public:
    int roll ;//extra member variable specific to Student class

    // Constructor for the derived class
    Student(string name, int age, int roll) : Person(name, age) { //inherits name and age from Person class and roll as its own member variable
        this->roll = roll; // Initialize the roll number
    }
};

//Another derived class
class GradStudent : public Student {
public:
    string researchArea;

    // Constructor for the derived class
    GradStudent(string name, int age, int roll, string degree) : Student (name, age, roll) {// inherits name, age, and roll from Student class
        // Initialize the research area
        this->researchArea = degree;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Research Area: " << researchArea << endl;
    }
};

int main() {
   
    // Create an object of the derived class
    GradStudent gradStudent("Alice", 25, 202, "Machine Learning");

    // Call the display method
    gradStudent.display(); // This will display name, age, roll number, and research area.
 
    return 0;
}