/*
    * Templates:
    Templates in C++ allow writing generic functions or classes to operate with different data types without rewriting code.
    A template is a blueprint or formula for creating a generic class or a function.
    * Why use templates?
        • Code reusability and flexibility of program.
        • Type independence patterns that can work with multiple data types 
        • Cleaner code
        • Templates are resolved at compile time, which can lead to faster code compared to runtime polymorphism.

    - When, an argument is passed to some_function( ), compiler generates new version of some_function() to work on argument of that type.
    - The templated type keyword specified can be either "class" or " typename".

    * Function Templates Or Generic Functions: 
        – These define logic behind the algorithms that work for multiple data types.
        
        Syntax:
            template <typename T>
                T add(T a, T b) {
                return a + b;
            }
            int main() {
                cout << add(3, 5);       
                cout << add(1.5, 7.3);    
            }

    * Class Templates OR Generic Classes:
        – These define generic class patterns into which specific data types can be plugged in to produce new classes.

        Syntax:
            template <class T>
            class MyPair {
                T a, b;
            public:
                MyPair(T x, T y) : a(x), b(y) {}
                T getMax() {
                    return (a > b) ? a : b; }
            };
            int main() {
                MyPair<int> p1(10, 20);
                cout << "Max is: " << p1.getMax() << endl;

                MyPair<double> p2(5.5, 2.3);
                cout << "Max is: " << p2.getMax() << endl;

                return 0;
            }

*/
    /*
        class PairIntString {
        int a;
        string b;
    public:
        PairIntString(int x, string y) : a(x), b(y) {}
        void display() {
            cout << a << "," << b;
        }
    };

    class PairDoubleChar {
        double a;
        char b;
    public:
        PairDoubleChar(double x, char y) : a(x), b(y) {}
        void display() {
            cout << a << "," << b;
        }
    };

        this is a example of Function Overloading. We can do the same work with template easyly, now doing it with template
    */


    // Multiple Type Parameters:

    #include <bits/stdc++.h>
    using namespace std;

    // Template class with two type parameters
    template <class T1, class T2>
    class Pair {
        T1 a;
        T2 b;
    public:

    
        // Constructor using member initializer list
        Pair(T1 x, T2 y) {
            a = x;
            b = y;
        }
        
        void display() {
            cout << a << "," << b; 
        }
    };

    int main() {
        cout << "Template classes with multiple parameters:" << endl;
        
        // Instantiation with int and string
        Pair<int, string> p(10, "Ten");
        p.display(); // Output: 10,Ten
        
        cout << endl;

        // Additional example: double and char
        Pair<double, char> p2(3.14, 'A');
        p2.display(); // Output: 3.14,A
        
        return 0;
    }   