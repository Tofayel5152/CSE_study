/*
    * Single level inheritance: One Parent to One Child

        Syntax:
        class subclass_name : access_mode <base_class>
        {
        // body of subclass
        };

*/

#include<bits/stdc++.h>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class
class Student : public Person {
public:
    int roll ;//extra member variable specific to Student class

    Student(string name, int age, int roll) : Person(name, age) {
        this->roll = roll;
    }

    void display() {
        Person::display();
        cout << "Roll Number: " << roll << endl;
    }
};

int main() {
    Student student("John Doe", 20, 101);
 
    student.display();

    return 0;
}