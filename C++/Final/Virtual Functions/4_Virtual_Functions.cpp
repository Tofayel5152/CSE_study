/*
    * Virtual Functions
        • A virtual function is a member function that is declared within a base class and redefined by a derived class.
        To create a virtual function, precede the function’s declaration with the keyword virtual. When a virtual function is
        redefined by a derived class, the keyword virtual is not needed.
        • Virtual functions implements the "one interface, multiple methods" philosophy under polymorphism. 
        • The virtual function within the base class defines the form of the interface to that function. 
        • Each redefinition of the virtual function by a derived class implements its operation as it relates 
        specifically to the derived class. That is, the redefinition creates a specific method. When a base pointer points to 
        a derived object that contains a virtual function and that virtual function is called through that pointer, C++
        determines which version of that function will be executed based upon the type of object being pointed to by the pointer.
        And, this determination is made at run time.

    * Rules for virtual functions:
        1. They can not be static.
        2. They are accessed by object pointers.
        3. They can be a friend of another class.
        4. A virtual function in base class might not be used.
        5. If a virtual function is defined in a base class, there is no need to define it in the derived class.
*/


#include <bits/stdc++.h>
using namespace std;

class Base // base class
{
public:
    virtual void show() // virtual function
    {
        cout << "Base\n";
    }
};

class Derv1 : public Base // derived class 1
{
public:
    void show()
    {
        cout << "Derv1\n";
    }
};

class Derv2 : public Base // derived class 2
{
public:
    void show()
    {
        cout << "Derv2\n";
    }
};

int main()
{
    Derv1 dv1; // object of derived class 1
    Derv2 dv2; // object of derived class 2
    Base *ptr;

    ptr = &dv1;  // put address of dv1 in pointer
    ptr->show(); // execute show() of Derv1

    ptr = &dv2;  // put address of dv2 in pointer
    ptr->show(); // execute show() of Derv2

    return 0;
}

/*

    * Another example Code:

    class CWH{

        protected:
        string title;
        int rating;

        public:
        CWH(string s, int r) {
            title = s;
            rating = r;
        }

        virtual void display(){}; // Now it is a vitual function, but not a pure virtual function. Difference is discussed in next lecture/code.
    };

    class CWHVideo : public CWH {
        float videoLength;

        public:
        CWHVideo(string s, int r, float vl) : CWH(s, r) {
            videoLength = vl;
        }

        void display() {
            cout << "This is an amazing video with title: " << title << endl;
            cout << "Rating: " << rating << " out of 5 stars" << endl;
            cout << "Length of this video is: " << videoLength << " minutes" << endl;
        }
    };

    class CWHText : public CWH {
        int words;

        public:
        CWHText(string s, int r, int w) : CWH(s, r) {
            words = w;
        }

        void display() {
            cout << "This is an amazing text tutorial with title: " << title << endl;
            cout << "Rating: " << rating << " out of 5 stars" << endl;
            cout << "Number of words in this text tutorial is: " << words << "words" << endl;
        }
    };

    int main(){

        string title;
        int rating;
        float vidLength;
        int words;

        // For Video
        title = "C++ Tutorial Video";
        rating = 4;
        vidLength = 15.5;
        CWHVideo cwhv(title, rating, vidLength);

        // For Text
        title = "C++ Tutorial Text";
        rating = 5;
        words = 1000;
        CWHText cwht(title, rating, words);

        CWH *cwh[2]; // Array of pointers to base class CWH
        cwh[0] = &cwhv; // Assigning address of CWH
        cwh[1] = &cwht; // Assigning address of CWH

        // Displaying the content
        for(int i = 0; i < 2; i++) {
            cwh[i]->display(); // Calls the display function of the derived class
            cout << endl;
        }


        return 0;
    }

*/