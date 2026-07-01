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

    Distance operator + (Distance d) {
        Distance temp; // Create a temporary Distance object
        temp.x = x + d.x; // Function to add a value to x
        return temp; // Return the new Distance object with the summed value
    }

    // Friend function to add value
    friend Distance operator + (Distance &d, int a);//prototype of friend function

};

Distance operator + (Distance &d, int a) {
    Distance temp; // Create a temporary Distance object
    temp.x = d.x + a; // Adds the integer value to the private member x of the Distance object
    return temp;
}

int main() {
    Distance d1; // Create a Distance object using the default constructor
    cout << "D1: "; d1.display(); // Display initial value of d1's x (should be 0)

    d1 = d1 + 10; // Call the friend function to add 10 to d1's x
    cout << "D1: "; d1.display(); // Display updated value of d1's x (should be 10)

    Distance d2(20); // Create another Distance object with initial value 20
    cout << "D2: "; d2.display(); // Display initial value of d2's x (should be 20)

    d2 = d2 + 10; // Call the friend function to add 10 to d2's x
    cout << "D2: "; d2.display(); // Display updated value of d2's x (should be 30)

    return 0;
}