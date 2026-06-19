/*
    * Pure Virtual Functions:
        A pure virtual function is a virtual function in C++ for which we need not to write any function definition and only we have to declare it in the base class and
        must be overridden in derived classes, or else they will become Abstract too. It is declared by assigning 0 in the declaration. It is a way to enforce that derived classes must implement this function.
    * Abstract Class: 
        An abstract class is a class that cannot be instantiated and is typically used to define an interface for derived classes. It contains at least one pure virtual
        function. Abstract class can have normal functions and variables along with a pure virtual function.
*/


#include<bits/stdc++.h>
using namespace std;

class CWH{// This class is now an abstract class

    protected:
    string title;
    int rating;

    public:
    CWH(string s, int r) {
        title = s;
        rating = r;
    }

    virtual void display() = 0; // This is a do-nothing function also known as a pure virtual function
    // A pure virtual function makes this class an abstract class.
    // Derived classes must define this function(Override the base display) or this code will not run.
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