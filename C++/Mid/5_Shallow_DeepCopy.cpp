/*A shallow copy of an object copies all of the member values from one object to another. It creates a new object that shares the same memory
locations for any dynamically allocated memory that the original object points to. This means that, if the original object has pointers to
dynamically allocated memory, the shallow copy will point to the same memory locations as the original object. If the original object is
modified, the shallow copy will reflect those changes, and vice versa. This can lead to issues like double deletion or memory corruption if
both objects try to delete the same memory. A shallow copy is typically created by the default copy constructor provided by the C++ compiler
or by using the assignment operator. In contrast, a deep copy creates a new object and allocates new memory for any dynamically allocated memory
that the original object points to. This means that the deep copy creates a completely independent copy of the original object, including all of
its member values and any dynamically allocated memory. A deep copy is typically implemented by defining a custom copy constructor or assignment
operator that explicitly copies the member values and allocates new memory for any pointers to dynamically allocated memory. Deep copy is useful
when the object contains pointers to dynamically allocated memory, as it ensures that each object has its own copy of the memory, preventing
issues like double deletion or memory corruption.
*/

#include<bits/stdc++.h>
using namespace std;

class Student{
    public:

    string name;
    int roll;
    //double gpa; //normal variable
    // If we want to use dynamic memory allocation for gpa, we can use a pointer
    double* gpaptr; // Pointer to dynamically allocated memory for gpa

    Student (string name,int roll,double gpa){
        this->name=name;
        this->roll=roll;
        gpaptr= new double; // Dynamically allocate memory for gpa in the heap
        *gpaptr = gpa; /*Assign the value to the pointed address by dereferencing the gpaptr and we need to use dereferencing
        operator to access the value every time we want to access gpa*/ 
    }

    // Student (Student &obj){ // Custom copy constructor for shallow copy
    //     this->name = obj.name; // Copying name
    //     this->roll = obj.roll; // Copying roll
    //     this->gpaptr = obj.gpaptr;   // Copying gpa *Main Difference*
    // }  // Note: This is a shallow copy, so if there were pointers, they would point to the same memory location.

    // Now for deep copy, we need to create a custom copy constructor
    Student (Student &obj){ // Custom copy constructor for deep copy
        this->name = obj.name; // Copying name
        this->roll = obj.roll; // Copying roll
        gpaptr = new double; // Allocate new memory for gpa *Main Difference*
        *gpaptr = *(obj.gpaptr); // Copy the value of gpa from the original object to the new memory location
    }

    void print(){
        cout<< "Name: "<< name << endl;
        cout<< "Roll: "<< roll <<endl;
        cout<< "Gpa: "<< *gpaptr << endl;
    }
};

int main(){
    Student s1( "Tofayel", 512,3.5);

     Student s2 (s1); // Shallow copy using default copy constructor

      s2.print(); // Print s2's details before modification

     *(s2.gpaptr) = 4.0; // Modifying gpa of s2

     s2.print(); // Print s2's details after modification
     s1.print(); // Print s1's details to see the effect of shallow copy. We can see that s1's gpa is also changed because of shallow copy

    // Now let's use deep copy
    Student s2 (s1); // Deep copy using custom copy constructor

    s1.print(); // Print s1's details before modification
    s2.print(); // Print s2's details before modification

    *(s2.gpaptr) = 4.0; // Modifying gpa of s2
    s2.name = "Shakib"; // Modifying name of s2

    s1.print(); // Print s1's details to see the effect of deep copy
    s2.print(); // Print s2's details after modification

}


/*Dynamic memory allocation*/
//By using 'new' keyword or pointer
//Basically, all variables and objects are stored in the stack memory, but if we use the 'new' keyword, it will be stored in the heap memory.
// Static memory allocation is done at compile time, while dynamic memory allocation is done at runtime.
// Shallow copy face issues when we have dynamic memory allocation or pointers in heap memory.
