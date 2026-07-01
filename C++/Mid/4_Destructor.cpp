/*Destroctor: A destructor is a special member function that is executed when an object of a class goes out of scope or is explicitly deleted.
It is used to release resources that the object may have acquired during its lifetime. It is defined using the tilde (~) symbol followed by the class name.
It deallocates any memory that was allocated for the object. Our compiler automatically generates a default destructor if we do not define one,
but it only deallocates memory for static members and does not handle dynamic memory allocation. If a class has dynamically allocated memory, we need to define
a custom destructor to release that memory properly. For deallocate memory, we use the delete operator in the destructor.
*/

#include<bits/stdc++.h>
using namespace std;

class Student{
    public:

    string name;
    int roll;
    double* gpaptr; // Pointer to dynamically allocated memory for gpa

    Student (string name,int roll,double gpa){
        this->name=name;
        this->roll=roll;
        gpaptr= new double; // Dynamically allocate memory for gpa in the heap
        *gpaptr = gpa; /* Assign the value to the pointed address by dereferencing the gpaptr and we need to use dereferencing
        operator to access the value every time we want to access gpa*/
    }

    //Destructor
    // ~Student(){ } // Custom defult destructor
    // It only deallocates memory for static members and does not handle dynamic memory allocation like gpaptr.

    ~Student(){ // Destructor to release dynamically allocated memory
        delete gpaptr; // Deallocate memory for gpa
        cout << "Destructor called for " << name << endl; // Optional: Print a message when destructor is called 
        //Destructor is called when the object ends its scope or is explicitly deleted
        // It is called automatically by the compiler when the main function ends.
    }

    void print(){
        cout<< "Name: "<< name << endl;
        cout<< "Roll: "<< roll <<endl;
        cout<< "Gpa: "<< *gpaptr << endl;
    }
};

int main(){
    Student s1( "Tofayel", 512,3.5);
    Student s2 ("Shakib", 513,4.0); 
    s1.print(); // Prints s1's details before going out of scope
    s2.print();
    // When s1 goes out of scope, the destructor will be called automatically

}