//Unary operator overloading: Increment operator (++)->(pre,post),Decrement operator (--)->(pre,post)
//Example of inrement operator overloading

#include <bits/stdc++.h>
using namespace std;

class Counter {
    int count;
public:
    Counter(){
        count = 0; // Constructor to initialize count to 0 (Default Constructor)
    }

    Counter(int c) {
        count = c; // Constructor to initialize count with a given value (Parameterized Constructor)
    }

   void display() {
        cout << "Count: " << count << endl; // Function to display the current count
    }

   Counter operator++() { // same for pre-decrement operator --> replace ++ with --
        Counter temp; // Create a temporary Counter object
        temp.count = ++count; // Pre-increment operator: increments count by 1 and assigns it to temp
        return temp; // Return the temporary object with the incremented count
    }

   Counter operator++(int) { // same for post-decrement operator --> replace ++ with --
        Counter temp; // Create a temporary Counter object
        temp.count = count++; // Post-increment operator: assigns current count to temp and then increments count by 1
        return temp; // Return the temporary object with the original count before increment
    }

    Counter operator -() { // same for unary plus operator --> replace - with +
        Counter temp; // Create a temporary Counter object
        temp.count = -count; // Unary minus: assigns current count to temp and negative its value.
        return temp;
    }
};

int main() {
    Counter c1,c2,c3; // Create Counter objects with default constructor
    c1.display(); // Display initial count (should be 0)
    c2.display(); // Display initial count (should be 0)

    c2 = c1++; // Post-increment
    c1.display(); // Display count after post-increment (should be 1)
    c2.display(); // Display count of c2 (should be 0, as it was assigned before increment)

    c2 = ++c1; // Pre-increment
    c1.display(); // Display count after pre-increment (should be 2)
    c2.display(); // Display count of c2 (should be 2, as it was assigned after post-increment->(c2=0->0+1->c2=1) and pre-increment->(c2=2))

    c3 = -c2; // Unary minus
    c3.display();

    return 0;
}
