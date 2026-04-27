/*Encapsulation is wrapping up of data & member functions in a single unit called class.-> Encapsulation is a fundamental concept
in object-oriented programming (OOP) that allows you to bundle data (attributes) and methods (functions) that operate on that data
into a single unit called a class. This helps in achieving data hiding and abstraction, which are key principles of OOP.*/

#include <bits/stdc++.h>
using namespace std;

class Account{
    private:
        double balance; // private member variable, not accessible outside the class
        string password;//data hiding
    public:
        string username; // public member variable, accessible from outside the class
        string accountID;
    
};// Encapsulation is achieved by using access specifiers private and public.