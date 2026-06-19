/*
    * Re-throwing Exception:
        In the program execution, when an exception received by catch block is passed to another exception handler then 
        such situation is referred to as re-throwing of exception. This is done with the help of following statement,
            throw; // re-throwing the exception
        The above statement does not contain any arguments. This statement throws the exception to next try catch block.
*/

#include <bits/stdc++.h>
using namespace std;

// Function for Exception Thrown
void exceptionFunction() {
    // try block - inside Function
    try {
        //throw exception : In function
        throw 0;
    } 
    catch (int i) {
        cout << "\nIn Function : Wrong Input :" << i;
        //re throw exception : out of the function
        throw;
    }
}

int main() {
    int var = 0;
    // try block - for exception code
    try {
        // Inside try block
        exceptionFunction();
    }// catch block
    catch (int ex) {
        // Code executed when exception caught
        cout << "\nIn Main : Wrong Input :" << ex;
    }
    return 0;
}
