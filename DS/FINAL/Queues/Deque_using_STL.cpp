// Deque means Double Ended Queue not Dequeue(removing an element from queue)
#include<bits/stdc++.h>
// bits/stdc++.h has all standard C++ libraries including <deque> that we need for STL deque.
using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(10); // Insert 10 at the back
    dq.push_back(20); // Insert 20 at the back
    dq.push_front(5); // Insert 5 at the front

    cout << "Front element: " << dq.front() << endl; // Output: 5
    cout << "Back element: " << dq.back() << endl;   // Output: 20

    dq.pop_front(); // Remove element from the front
    cout << "Front element after pop_front: " << dq.front() << endl; // Output: 10
    cout << "Back element remains: " << dq.back() << endl;   // Output: 20
    dq.pop_back();  // Remove element from the back 
    cout << "Front element remains: " << dq.front() << endl; // Output: 10
    cout << "Back element after pop_back: " << dq.back() << endl;   // Output: 10

    return 0;
}