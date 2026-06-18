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
        Point temp;
        temp.x = x && p.x;
        temp.y = y && p.y;
        return temp.x  && temp.y;
    }

    // Overload ||
    bool operator || (Point p) {
        Point temp;
        temp.x = x || p.x;
        temp.y = y || p.y;
        return temp.x || temp.y;
    }

    // Overload !
    bool operator ! () {
        Point temp;
        temp.x = !x;
        temp.y = !y;
        return temp.x && temp.y; // Use the overloaded ! operator to check if both x and y are zero
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