/*
    * Virtual Base Class :
        Suppose we have two derived classes B and C that have a common base class A, and we also have another class D that inherits from B and C. We can declare the 
        base class A as virtual to ensure that B and C share the same sub object of A.

        => A virtual base class is a base class that is inherited by multiple derived classes. It ensures that only one instance of the virtual base class is created, 
        even if it is inherited by multiple derived classes.

        • Virtual base classes are used to resolve the diamond problem in hybrid inheritance.
        • The virtual keyword is used to declare a virtual base class.
        • When a class inherits from a virtual base class, it must initialize the virtual base class in its constructor.

        Diamond Problem:
        The diamond problem is a problem that arises in hybrid inheritance when two or more classes inherit from the same base class and another class inherits from both. 
        This can lead to ambiguity and confusion when trying to access members of the base class.

*/

#include <bits/stdc++.h>
using namespace std;

class A { // Virtual base class
public:
    void eat() { cout << "Eat!"; }
};

class B : virtual public A {  // Virtual inheritance
public:
    void funcB() { 
        cout << " B"; 
    }
};

class C : virtual public A { // Virtual inheritance
public:
    void funcC() { 
        cout << " C"; 
    }
};

class D : public B, public C { // Multiple inheritance

}; 

int main() {
    D d;
    d.eat(); // Works without ambiguity!
    return 0;
}

/* 
    Here, Without virtual, class D would contain two separate copies of class A (one via B, one via C), causing ambiguity when calling eat().
    By using virtual public A:
        1. Shared Base: B and C share the same single instance of A.
        2. No Ambiguity: The compiler knows exactly which eat() to call because there is only one path to the base class A.
        3. Memory Efficiency: It prevents duplicating the base class data members in memory.

*/