/*
    * Constructors and Destructors in Inheritance:
    => It is possible for the base class, the derived class, or both to have constructor and/or destructor functions.
        · In (allocation or constructor) call the base class constructor is called first, followed by the derived class constructor.
        · In (deallocation or destructor) call the derived class destructor is called first, followed by the base class destructor.

        * constructor and destructor functions EXAMPLE :
        # include <Bits/stdc++.h>
        using namespace std;
        class base {
        public :
            base () { cout << " Constructing base class \n"; }
            ~ base () { cout << " Destructing base class \n"; }
        };
        class derived : public base {
        public :
        derived () { cout << " Constructing derived class \n"; }
        ~ derived () { cout << " Destructing derived class \n"; }
        };
        int main () {
        derived o;
        return 0;
        }

        => This program displays the following output:
            Constructing base class
            Constructing derived class
            Destructing derived class
            Destructing base class

*/
#include <bits/stdc++.h>
using namespace std;

class Base{
    public:
        Base() { // Default constructor for Base class
            cout << "Base" << endl;
        }
        Base (int a){ // Parameterized constructor for Base class
            cout << "From Base: value of a = " << a << endl; 
        }
};

class Derived : public Base {
    public:
        Derived () : Base (){ // Default constructor for Derived class that calls the default constructor of Base class also prints "Derived"
            cout << "Derived" << endl; 
        }

        Derived(int d) : Base (d){ // Parameterized constructor for Derived class that calls the parameterized constructor of Base class with value d

        }
};

int main (){
    Derived obD, obD2 (10) ;

    return 0;
}
