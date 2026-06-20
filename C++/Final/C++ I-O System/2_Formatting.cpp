/*
    * Formatting using the ios members:
        The stream has the format flags that control the way of formatting. it means Using this setf function, we can set the flags, 
        which allow us to display a value in a particular format. Few standard ios class functions are:
        • width(): The width method is used to set the required field width. The output will be displayed in the given width
        • precision(): The precision method is used to set the number of the decimal point to a float value
        • fill(): The fill method is used to set a character to fill in the blank space of a field
        • setf(): The setf method is used to set various flags for formatting output
        • unsetf(): The unsetf method is used To remove the flag setting
*/

#include<bits/stdc++.h>
using namespace std;

void IOS_width()
{
    cout << "Implementing width:\n";
    char c = 'A';
    cout.width(5);
    cout << c <<"\n";
    int temp = 10;
    cout<<temp << endl;
}
void IOS_precision()
{
    cout << "Implementing precision:\n";
    cout.precision(2);
    cout<<3.1422 << endl; // Output will be 3.1 because it will round the value to 2 places.
    // To get the output 3.14 we need to use fixed manipulator
    cout << fixed << setprecision(2) << 3.1422 << endl;
}
// The fill() function fills the unused white spaces in a value with a character of choice. 
void IOS_fill()
{
    cout << "Implementing fill:\n";
    char ch = 'a';
    cout.fill('*');
    cout.width(10);
    cout<<ch <<"\n";
    int i = 1;
    cout.width(5);
    cout<<i << endl;
}
void IOS_setf()
{
    cout << "Implementing setf:\n";
    int val1=100, val2=200;
    cout.setf(ios::showpos);
    cout<<val1<<" "<<val2 <<endl;
}
void IOS_unsetf()
{
    cout << "Implementing unsetf:\n";
    cout.setf(ios::showpos|ios::showpoint);
    // Clear the showflag flag without affecting the showpoint flag
    cout.unsetf(ios::showpos);
    cout<<200.0;
    }

int main()
{
    IOS_width();
    IOS_precision();
    IOS_fill();
    IOS_setf();
    IOS_unsetf();
return 0;
}

/*
    * Output:
        Implementing width:
            A
        10
        Implementing precision:
        3.1
        3.14
        Implementing fill:
        *********a
        ****1
        Implementing setf:
        +100 +200
        Implementing unsetf:
        200.00
*/