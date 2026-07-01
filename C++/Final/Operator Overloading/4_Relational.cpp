//Relational Operators:<, >, <=, >=, ==, !=
#include <bits/stdc++.h>
using namespace std;

class Point {
    int x, y;
public: 

    Point(){
        x = 0;
        y = 0;
    }

    Point(int a, int b){
        x = a;
        y = b;
    }

    // Overload ==
    bool operator == (Point p){
        if (x == p.x && y == p.y)
            return true;
        else
            return false;
    }

    // Overload <
    bool operator < (Point p){
        if (x < p.x && y < p.y)
            return true;
        else
            return false;
    }

    // Overload !=
    bool operator != (Point p){
        if (x != p.x || y != p.y)
            return true;
        else
            return false;
    }

};

int main() {
    Point p1(2, 3), p2(2, 3), p3(1, 1);

    if (p1 == p2)
        cout << "p1 is equal to p2\n";

     if (p1 != p3)
        cout << "p1 is not equal to p3\n";

    if (p3 < p1)
        cout << "p3 is less than p1\n";
        else
        cout << "p3 is not less than p1\n";

    return 0;
}