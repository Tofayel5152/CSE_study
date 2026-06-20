/*
    * Stream:
        In C++, a stream refers to a sequence of characters or bytes that are transferred between the program and input/output (I/O) devices.

    * INPUT PROCESS & OUTPUT PROCESS: cin(input stream) and cout(output stream) 
   
   [ I/P Device ] 
         │
         ▼
   ( Read data )
         │
         ▼
   ┌──────────────┐
   │ Input Stream │
   └──────┬───────┘
          │
          ▼
   ( Extraction from i/p stream ) ───► ( Input Data ) ───► [  P R O G R A M  ] ───► (Output Data) ───►  ( Insertion into o/p stream )
                                                                                                                    │
                                                                                                                    ▼
                                                                                                            ┌──────────────┐
                                                                                                            │ Output Stream│
                                                                                                            └──────┬───────┘
                                                                                                                   │
                                                                                                                   ▼
                                                                                                              ( Write data )
                                                                                                                   │
                                                                                                                   ▼
                                                                                                              [ O/P Device ] 
                                                                                                               
    
    * Stream classes:
        Stream classes in C++ are used to input and output operations on files and I/O devices. These classes have specific features and to handle 
        input and output of the program. 
        1. iostream class − This class is responsible for handling both input and output stream as both istream class and ostream class is inherited into it. 
        It provides function of both istream class and ostream class for handling chars, strings and objects such as get, getline, read, ignore, putback, 
        put, write etc. 
        2. istream Class − The istream class handles the input stream in c++ programming language. These input stream objects are used to 
        read and interpret the input as a sequence of characters. The cin handles the input. 
        3. ostream class − The ostream class handles the output stream in c++ programming language. These output stream objects are used to write data as 
        a sequence of characters on the screen. cout and puts handle the output streams in c++ programming language.

    * File I/O:

       <-----File<--------
       |                 |
    |Read|            |Write|
        |                |
        ---->Programe---->
                |
    |Console|<--|-->|Console|
    input       |    output
    from        |    to
    keyboard    |    screen

        File I/O (Input/Output) refers to the process of reading from and writing to files in a programming language. In C++, file I/O is typically performed 
        using the fstream library, which provides classes and functions for working with files.(#include<fstream> (but #include<bits/stdc++.h> contains all header files))
        fstream library provides three main classes for file I/O operations:
            1. fstreambase
            2. ifstream --> derived from fstreambase(take input from file to programe means programe will read)
            3. ofstream --> derived from fstreambase(take output from programe to file means programe will write)

    * Opening a file:
    In order to work with files in C++, you will have to open it. primarily, there are 2 ways to open a file:
    1. Using the constructor
    2. Using the member function open() of the class

    * Closing a file:
    After performing the desired operations on a file, it is important to close the file to free up system resources and ensure that all data is properly saved.
    In C++, you can close a file using the close() member function of the file stream class.

    * Reading from a file:
    To read from a file in C++, you can use the ifstream class. You can read data from a file using various member functions such as getline(), get(), read(), etc. 
    The getline() function is commonly used to read an entire line of text from a file. You can also use read() function to read a specific number of bytes from a file.

    * Writing to a file:
    To write to a file in C++, you can use the ofstream class. You can write data to a file using the insertion operator (<<) or the write() member function. The insertion 
    operator allows you to write formatted data to a file, while the write() function allows you to write raw bytes to a file.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string st1;

    //Opening with constructor and read it
    ifstream hin ("sample.txt");

    /*
    cin >> st1; //this will only read the first word if any space or end line comes the output will not show after that so we will use 
    [getline( / stream(cin or hin) /  , / stringVariable (string name) / );] function which reads the entire line.
   */ 

    getline (hin , st1); // This will show one line but to show another line we need to use getline() another time
    getline (hin , st1); // But this will show only the second line, first line will not be shown if 2 of this getline execute.

    cout << st1;

    string st2;
    cout << "Enter name: ";
    cin >> st2;

    //Opening with constructor and write it
    ofstream Nout ("sample1.txt");

    Nout << "My name is " + st2;

    Nout.close(); // Terminate the connection between file and program of Nout

    ofstream out;
    out.open("sample.txt");
    out << "This is Tofayel\n";
    out << "This is my programe\n";
    out << "This programe works with File I/O\n";

    out.close();

    ifstream in;
    string st;

    in.open("sample.txt");

    // while(in.eof() == 0){
    // While checks the condition, until the condition is true it runs. eof() (means end of line which is 0) so it will stop if the eof is reached. 
    //     getline(in,st);
    //     cout << st << endl;
    // }

    while (getline(in,st)){// while loop will run until getline is false/0 means end of line.

        cout << st << endl;

    }

    in.close();

    return 0;
}