/*
    * Nesting of Classes:
    · A nested class is a class which is declared in another enclosing class. 
    · A nested class is a member and as such has the same access rights as any other member. 
    · A nested class is declared within the scope of another class.

*/

#include <bits/stdc++.h>
using namespace std;

// A nested class is declared within the scope of another class.
class A {
public:
    class B {
    private:
        int num;
    public:
        void getdata(int n) {
            num = n;
        }
        void putdata() {
            cout << "The number is " << num;
        }
    };
};

int main() {
    cout << "Nested classes in C++" << endl;
    
    // Instantiation requires the scope resolution operator
    A::B obj; 
    
    obj.getdata(9);
    obj.putdata();
    
    return 0;
}   