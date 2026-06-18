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
       Point tamp;
       tamp.x = x == p.x;
       tamp.y = y == p.y;
        return (tamp.x && tamp.y);
    }

    // Overload <
    bool operator < (Point p){

        Point temp;
        temp.x = (x + y);
        temp.y = (p.x + p.y);
        return temp.x < temp.y;

    }

    // Overload !=
    bool operator != (Point p){
        Point temp;
        temp.x = x != p.x;
        temp.y = y != p.y;
        return (temp.x && temp.y); // Use the overloaded != operator to check inequality
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