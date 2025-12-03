#include<bits/stdc++.h>
// bits/stdc++.h has all standard C++ libraries including <queue> that we need for STL queue.
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 30
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Undefined behavior, queue is empty so output will vary(normally 0 or garbage value)

    return 0;
}