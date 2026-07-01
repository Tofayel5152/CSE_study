/*Constructors in C++ are special member functions that are automatically called when an object of a class is created. They are used to initialize the
object's attributes and allocate resources if necessary. Constructors can be overloaded, meaning you can have multiple constructors with different
parameters.
They do not have a return type, not even void, and their name must match the class name. Constructors can also have default parameters, allowing for
flexible object creation.
Constructors can be defined in three ways: default constructors (which take no parameters) and parameterized constructors (which take parameters to
initialize the object with specific values) and copy constructor (which takes a reference to an object of the same class).
Constructors are essential for ensuring that objects are in a valid state when they are created, and they can also be used to enforce certain
constraints or invariants on the object's data.
*/
#include<bits/stdc++.h>
using namespace std;

// Class representing a student
class Student {
    public:
    string name;
    int roll;
    double gpa;

    //Constructor

    /* Default constructor.
    This constructor takes no parameters and initializes the object with default values. If we do not define any constructor, C++ provides a default 
    constructor that initializes the members to their default values but if we define any constructor, C++ does not provide a default constructor
    and we have to define it ourselves if we want to use it. without a default constructor, we cannot create an object without passing it through
    parameterized constructor.
    A default constructor is a constructor that takes no arguments. It can be defined in two ways:
    1. By using the default keyword: Student() = default;
    2. By defining a constructor with no arguments: Student() {
        name = "Unknown"; // Initialize name to "Unknown"
        cout << "non-parameterized (default) constructor called" << endl;
    }
    */
    Student() {
        name = "Unknown"; // Initialize name to "Unknown"
        cout << "non-parameterized (default) constructor called" << endl;
    
    }

    /* Parameterized constructor
    This constructor takes parameters and initializes the object with the provided values. it is not necessary to pass all parameters to the constructor
    we can pass only the required parameters and leave the rest to be initialized later.
    */
    /* We can also use multiple constructors in a class, which is called constructor overloading. In c++, we can have multiple constructors with 
    different parameters in the same class.But they must have different signatures (i.e., different parameter lists and their position of initalization).
    This allows us to create objects in different ways, depending on the parameters we pass to the constructor.
    For example, we can have a constructor that takes only the name and roll, and another that takes all three parameters. (Like in code below)
    */
    Student(string n, int r/*, double g*/) {
        name = n; // Initialize name with the provided parameter
        roll = r;
        /* gpa = g; Like this i want to initialize gpa with default constructor so i am not initializing it here and for that i will only pass the name
        and roll parameters.*/
        cout << "parameterized (2 parameter) constructor called" << endl;
    }

    Student(string name, int roll, double gpa) { // Another parameterized constructor with all parameters
        this->name = name;
        this->roll = roll;
        this->gpa = gpa; 
        /* The 'this' pointer (keyword) is a pointer that points to the current object of the class. It is used to distinguish between the member
        variables of the class and the parameters passed to the constructor. But the compiler will not show any error if we don't use 'this' pointer
        because it will consider the constructor as a function and not as a constructor. And it will show some garbage values as output.*/
        cout << "parameterized (3 parameter) constructor called" << endl;
    }

    /* Copy constructor
    This constructor takes a reference to an object of the same class and initializes the object with the provided values.It is called when we create
    a new object from an existing object, like Student s4 = s1; or Student s5(s2);
    */
    Student(Student &s) { // It's a Custom copy constructor,normaly a default copy constructor exist in C++ but we can aslo define our own copy constructor like this.
        this->name = s.name;
        this->roll = s.roll;
        this->gpa = s.gpa;
        cout << "copy constructor called" << endl;
    }

    void printStudentInfo() {
    cout << "Name: " << name << endl;
    cout << "Roll: " << roll << endl;
    cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Student s1; 
    s1.name = "asia"; // Calls the default constructor
    s1.roll = 101;
    s1.gpa = 3.8;
    
    s1.printStudentInfo();

    Student s2("Tofayel",512/*,3.5*/); // Calls the parameterized constructor
    s2.gpa = 3.5;/* Here we are initializing gpa after object creation because we didn't pass it to the parameterized constructor. It is initialized
    with default constructor. We can also overwrite any value of the object after it is initialized by the constructor.*/
    s2.printStudentInfo();
    
    s1.roll = 5152; // Overwriting roll after object creation
    s1.printStudentInfo();

    Student s3("Bob", 102, 3.9);
    /* Create and initialize object of Student by using another parameterized constructor. When executing multiple constructors, the one that matches
    the parameters passed during object creation will be called. If no matching constructor is found, the default constructor will be called if it
    exists. If no constructor is defined, the compiler provides an error because it cannot create an object without a constructor.*/
    s3.printStudentInfo();
    
    Student s4 = s1; // Copy constructor is called here, which is a deep copy of s1, because we can change the values of s4 without affecting s1.
    s4.name = "Charlie"; // Changing name of s4 does not affect s1

    Student s5 (s2); // Copy constructor is called here, which is a deep copy of s2, because we can change the values of s5 without affecting s2.
    s5.roll = 202; // Changing roll of s5 does not affect s2

    s4.printStudentInfo();
    s5.printStudentInfo();

    /*Depending on the context, the object can take on different forms like in the above example s1 calls the non-parameterized constructor and s2 calls
    the parameterized constructor. This is an example of constructor overloading, which is a form of polymorphism in C++.
    */

    return 0;
}