/*
    * Exception:
        -  An exception is an unexpected problem that arises during the execution of a program. Exceptions are run time errors which occur at runtime 
        like low disk space, division by zero, access to array outside its bounds.
        - Exceptions are of two types. They are synchronous exceptions and asynchronous exceptions. Errors like out of range index or overflow come 
        under synchronous exceptions and errors which are beyond the program like keyboard interrupts,low disk space are called as asynchronous exceptions.
    * Exception Handling in C++ is a mechanism to:
        - Detect errors at runtime
        - Handle those errors gracefully
        - Prevent abnormal program termination

    * Why Use Exception Handling?
        Traditionally, errors were handled using return codes or flags, but that can clutter the code and be unreliable. With exception handling, normal 
        logic is separated from error-handling logic.

    * C++ exception handling is built upon three keywords: try, throw, catch.
        1. Try: Defines a block of code to test for errors. A try block identifies a block of code for which particular exceptions will be activated. It's
        followed by one or more catch blocks.
            try {
                / risky code /
            }

        2.Throw:  A program throws an exception when a problem shows up. This is done using a throw keyword.
            Signals an error( exception)
            throw "Division by zero!";

        3. Catch: Defines how to handle the thrown error. A program catches an exception with an exception handler at the place in a program where you want 
        to handle the problem. The catch keyword indicates the catching of an exception.
            catch (const char* message) {
                cout << "Error: " << message;
            }
            - To catch any type of exception, use (...)
            catch (...) {
                cout << "Unknown exception caught!";
            }
        

    * Multiple catch blocks:
        - A single try block can have multiple catch blocks. Each catch block is an exception handler that handles a specific type of exception. The catch 
        blocks are checked in the order in which they appear. The first catch block that matches the type of the thrown exception is executed.

        Example:
            try {
                / throw 5; /
                throw "Hello";
            }
            catch (int e) {
                cout << "Caught int: " << e;
            }
            catch (const char* e) {
                cout << "Caught string: " << e;
            }

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int numerator, denominator, result;

    cout << "Enter numerator and denominator: " << endl;

    cin >> numerator >> denominator;

    try
    {
        if (denominator == 0)
        { // check if denominator is zero

            throw denominator;//throw is like a break keyword 

        }

        result = numerator / denominator; // division happens here if no exception arises, means not thrown
        cout << "Division is : " << result << endl;
    }
    catch (int ex)
    {
        cout << "Exception: Divide by zero not allowed! For " << ex << endl;
    }

    return 0;
}

/*
    * Advantages of Exception Handling:
        (a) Exception handling can control run tune errors that occur in the program. 
        (b) It can avoid abnormal termination of the program and also shows the behavior of program to users. 
        (c) It can provide a facility to handle exceptions, throws message regarding exception and completes the execution of program by catching the exception
        (d) It can separate the error handling code and normal code by using try-catch block. 
        (e) It can produce the normal execution flow for a program. 
        (f) It can implement a clean way to propagate error. that is. when an invoking method cannot manage a particular situations, then it throws an exception
        and asks the invoking method to deal with such situation.
        
*/