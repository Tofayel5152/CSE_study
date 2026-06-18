// Assignment Operator Overloading (=)
#include <bits/stdc++.h>
using namespace std;

class Marks {
    int internal;
    int external;

public:
    // Default Constructor
    Marks() {
        internal = 0;
        external = 0;
    }

    // Parameterized Constructor
    Marks(int im, int em) {
        internal = im;
        external = em;
    }

    // Overloading the assignment operator (=)
    // It returns a reference to the current object to allow chained assignments (m1 = m2 = m3)
    Marks& operator= (Marks &m) {   // same for += , -= , *= , /= , %=  just replace with =
        // Check for self-assignment
        if (this != &m) {
            this->internal = m.internal;
            this->external = m.external;
        }
        return *this; // "this" pointer is a constant pointer that holds the memory address of the current object.
    }

    /* Also can be done by,
        void operator = (Marks &m){
            this->internal = m.internal;
            this->external = m.external;
        }

        void operator += (Marks &m){
            this->internal += m.internal;
            this->external += m.external;
        }
    */

    void display() {
        cout << "Internal Marks: " << internal << ", External Marks: " << external << endl;
    }
};

int main() {
    Marks m1(45, 85);
    Marks m2;

    cout << "M1 before assignment: ";
    m1.display();
    cout << "M2 before assignment: ";
    m2.display();

    // Using overloaded assignment operator
    m2 = m1;

    cout << "\nAfter assignment (m2 = m1):" << endl;
    cout << "M1: ";
    m1.display();
    cout << "M2: ";
    m2.display();

    // Chained assignment
    Marks m3;
    m3 = m2 = m1;
    cout << "\nAfter chained assignment (m3 = m2 = m1):" << endl;
    m3.display();

    return 0;
}
