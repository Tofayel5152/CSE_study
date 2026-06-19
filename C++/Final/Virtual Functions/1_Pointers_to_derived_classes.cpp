/*
    * Pointers to derived classes:
        · A Pointer, declared as a Pointer to a base class can also be used to point to any class derived from that base class. 
        For example: assume two classes called base and derived, where derived inherits base.
        · Base pointer can point to an object of any class which is derived from that base class. The reverse is not true.
        That is, a pointer of the derived class cannot be used to access an object of the base class.
        · Although you can use a base pointer to point to a derived object, you can access only those members of the derived
        object that were inherited from the base. This is because the base pointer has knowledge only of the base class.
        It knows nothing about the members added by the derived class.

        Syntax:
            base *p; // base class pointer
            base base_obj ; // object of type base named base_obj.
            derived derived_obj ; // object of type derived named derived_obj.
            / p can point to base objects /
            p = &base_obj ; // p points to base object
            / p can also point to derived objects without error /
            p = &derived_obj ; // p points to derived object
*/

    # include <bits/stdc++.h>
    using namespace std;
    class base {
            int x;
        public :
            void setx (int i) {
                x = i;
            }
            int getx () {
                return x;
            }
    };
    class derived : public base {
            int y;
        public :
            void sety (int i) {
                y = i;
            }
            int gety () {
                return y;
            }
    };
    int main (){
        base *p; // pointer to base type
        base b_obj ; // object of base
        derived d_obj ; // object of derived

            // use p to access base object
        p = & b_obj ;
        p-> setx (10) ; // access base object. 
            /*  
            -> This syntax is commonly used in object- oriented programming languages like C++ to access member functions and
            variables of an object through a pointer to that object. 
            */
        cout << " Base object x: " << p-> getx () << endl; 

            // use p to access derived object
        p = &d_obj ; // point to derived object
        p-> setx (99) ; // access derived object

            // can ’t use p to set y, so do it directly
        d_obj.sety (88) ;
        cout << " Derived object x: " << p-> getx () << endl;
        cout << " Derived object y: " << d_obj . gety () << endl;

        return 0;
    }