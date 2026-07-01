//Logical operators : &&,||,!
#include<bits/stdc++.h>
using namespace std;

class Point {

    int x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int a, int b) {
        x = a;
        y = b;
    }

    // Overload &&
    bool operator && (Point p) {
        if ((x && p.x) && (y && p.y))
            return true;
        else
            return false;
    }

    // Overload ||
    bool operator || (Point p) {
       if ((x || p.x) || (y || p.y))
            return true;
        else
            return false;
    }

    // Overload !
    bool operator ! () {
        if (!x && !y)
            return true;
        else
            return false; // Return true if both x and y are zero, indicating the point is at the origin(0,0)
    }

};

int main() {
    Point p1(2, 3), p2(0, 0), p3(1, 1);

    if (p1 && p3)
        cout << "p1 and p3 are both non-zero\n";

    if (p1 || p2)
        cout << "Either p1 or p2 is non-zero\n";

    if (!p2)
        cout << "p2 is zero\n";

    return 0;
}