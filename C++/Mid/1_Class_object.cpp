#include<bits/stdc++.h>
using namespace std;

class Teacher{
    /* Class (Teacher) -> A class is a user-defined data type that allows us to combine data and functions that operate on
    that data into a single unit. It serves as a blueprint for creating objects, encapsulating both attributes
    (data members) and behaviors (member functions).
    */
private: // Not necessary to write private as it is default in C++. But good for readability.
     double salary; // private member variable, not accessible outside the class
     //To access this variable, we can use a setter-getter method

public:// access specifier:-> public, private, protected
    //public members can be accessed from outside the class
    //private members can only be accessed from within the class(By default, all members are private in C++)
    //protected members can be accessed from within the class and it's derived classes

    //properties/attributes (salary is also a property/attribute but it is private)
    string name;
    string dept;
    string subject;

    //methods/member functions

    void printinfo(){//passing object to function and printing teacher information
        cout << "Name: " << name << ", " << "Department: " << dept << ", " << 
        "Subject: " << subject<< endl;
    }

    void change(Teacher t){//pass by value
    // This function attempts to change the name of the teacher (but it will not change because it is pass by value)
    t.name = "Changed Name";
    }

    void changee(Teacher &t){//pass by reference
    // This function changes the name of the teacher (and it will change because it is pass by reference)
    t.name = "Changed Name";
    }

    // method to change the department of the teacher (setter method)
    void changedept(string newdept){
        dept = newdept;
    }

    // setter method to set the salary
    void setSalary(double newSalary) {
        salary = newSalary;
    }
    // getter method to get the salary
    double getSalary(){
        return salary;
    }

};

int main(){
    Teacher t1;/* Object (t1) -> Objects are instances of classes, and they can have their own unique data while
    sharing the structure and behavior defined by the class. */
    t1.name = "John Doe";
    t1.dept = "Mathematics";
    t1.subject = "Calculus";

    t1.printinfo();

    // Setting the salary using setter method
    t1.setSalary(50000);
    // Getting the salary using getter method
    cout << "Salary: " << t1.getSalary() << endl;

    // Changing the department of the teacher
    t1.changedept("Physics");
    cout << "Updated Department: " << t1.dept << endl;

    t1.printinfo();

    // Pass by value
    t1.change(t1);
    cout << "Name after pass by value: " << t1.name << endl;

    t1.printinfo();
    
    // Pass by reference
    t1.changee(t1);
    cout << "Name after pass by reference: " << t1.name << endl;

    t1.printinfo();

    return 0;
}