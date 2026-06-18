/*
    Operator Overloading:
    Operator overloading is a compile-time polymorphism in which the operator is overloaded to 
    provide the special meaning to the user-defined data type. Operator overloading is used to 
    overload or redefines most of the operators available in C++. It is an idea of giving special 
    meaning to an existing operator in C++ without changing its original meaning. The mechanism 
    of giving special meaning to an operator is known as operator overloading.

    We can overload all C++ operator except the following:
        1. Class member access operator (., .* )
        2. Scope resolution operator( :: )
        3. Size operator (sizeof)
        4. Conditional operator( ?: )

    Operators:
    1. Arithmatic Operators:
        A. Unary Operators:  (***)
            a. Increment (++)
            b. Decrement (--)
            c. Unary minus (-)
            d. Unary plus (+)

        B. Binary Operators: (***)
            a. Plus (+)
            b. Minus (-)
            c. Multiply (*)
            d. Divide (/)
            e. Modulo (%)
            
    2. Relational Operators: (***)
        a. Less than (<)
        b. Greater than (>)
        c. Less than or equal to (<=)
        d. Greater than or equal to (>=)
        e. Equal to (==)
        f. Not equal to (!=)

    3. Logical Operators: (***)
        a. AND (&&)
        b. OR (||)
        c. NOT (!)

    4. Assignment Operators:
        a. Assignment (=) (***)
        b. Addition assignment (+=)
        c. Subtraction assignment (-=)
        d. Multiplication assignment (*=)
        e. Division assignment (/=)
        f. Modulo assignment (%=)

    
    Example of Binary Operator Overloading: The + operator is overloaded to add two objects of a
    class that represents marks, allowing us to combine their internal and external marks
*/

//Plus operator to oveload for obj and int.

// #include<bits/stdc++.h>
// using namespace std;

// class Marks {
//     int internal;
//     int external;
// public:
//     Marks(){
//         internal = 0;
//         external = 0;
//     }

//     Marks(int im, int em) {
//         this->internal = im;
//         this->external = em;
//     }

//     void display() {
//         cout << "Internal Marks: " << internal << ", External Marks: " << external << endl;
//     }


//     Marks operator + (int x){
//         Marks temp;// Create a temporary Marks object to hold the result
//         temp.internal = internal + x;// Add internal marks
//         temp.external = external + x;// Add external marks
//         return temp; // Return the new Marks object with summed values
//     }
    
// };
// int main() {
//     int x = 100;
//     Marks m1(30, 70); 

//     cout << "Marks 1: ";
//     m1.display(); // Display first Marks object

//     Marks m3 = m1 + x;

//     cout << "Combined Marks: ";
//     m3.display(); // Display the combined Marks object

//     return 0;
// }


//Plus operator to oveload for obj and obj.

#include<bits/stdc++.h>
using namespace std;

// Class representing Internal mark and External mark
class Marks {
    int internal;
    int external;
public:
    // Constructor to initialize internal and external marks
    Marks(){
        internal = 0;
        external = 0;
    }

    Marks(int im, int em) {
        this->internal = im;
        this->external = em;
    }

    void display() {
        cout << "Internal Marks: " << internal << ", External Marks: " << external << endl;
    }

    // Overloading the + operator to add two Marks objects
    // This function takes another Marks object as a parameter and returns a new Marks object
    Marks operator + (Marks m){
        Marks temp;// Create a temporary Marks object to hold the result
        temp.internal = internal + m.internal;// Add internal marks
        temp.external = external + m.external;// Add external marks
        return temp; // Return the new Marks object with summed values
    }

    // - operator overloading
    // Marks operator - (Marks n){
    //     return Marks(internal - n.internal , external - n.external);
    // }

};
int main() {
    Marks m1(30, 70); // Create first Marks object with internal and external marks
    Marks m2(20, 80); // Create second Marks object with internal and external marks

    cout << "Marks 1: ";
    m1.display(); // Display first Marks object

    cout << "Marks 2: ";
    m2.display(); // Display second Marks object

    Marks m3 = m1 + m2; // Use the overloaded + operator to add two Marks objects
    // Marks m4 = m3 - m2;

    cout << "Combined Marks: ";
    m3.display(); // Display the combined Marks object

    // cout << "Substracted Marks: ";
    // m4.display();

    return 0;
}