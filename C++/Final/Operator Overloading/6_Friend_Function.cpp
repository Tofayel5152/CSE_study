/*
->What is Friend Function ?
• A friend function of a class is defined outside that class scope but it has the right to access all private and protected members of the class.
• Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

->Why do we need Friend function ?
• Consider a situation where we need to use two different types of operands for binary operator. One an object and another a built-in -data type.
    Ex: d1 = d0 + 20; d2 = d1 + d0;
• Special case when class's private data needs to be accessed directly without using object of that class.
• Operator overloading
*/

#include <bits/stdc++.h>
using namespace std;

class Distance {
    int x;

    public:
    Distance() {
        x = 0; // Default constructor initializes x to 0
    }
    Distance(int a) {
        x = a; // Parameterized constructor initializes x with the given value
    }

    void display() {
        cout << "Distance: " << x << endl; // Function to display the current value of x
    }

    // Friend function to add value
    friend void Add (Distance &d);//prototype of friend function

};

void Add (Distance &d) {
    d.x = d.x + 10; // Adds 10 to the private member x of the Distance object
}
int main() {
    Distance d1; // Create a Distance object using the default constructor
    d1.display(); // Display initial value of d1's x (should be 0)

    Add (d1); // Call the friend function to add 10 to d1's x
    d1.display(); // Display updated value of d1's x (should be 10)

    Distance d2(20); // Create another Distance object with initial value 20
    d2.display(); // Display initial value of d2's x (should be 20)

    Add (d2); // Call the friend function to add 10 to d2's x
    d2.display(); // Display updated value of d2's x (should be 30)

    return 0;
}