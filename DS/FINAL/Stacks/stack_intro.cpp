#include <bits/stdc++.h>
using namespace std;

class StackLL {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* top;      // Points to top of stack
    int count;      // Number of elements

public:
    // Constructor
    StackLL() : top(nullptr), count(0) {}

    // Destructor
    ~StackLL() {
        while (!isEmpty()) {
            pop();
        }
    }

    // PUSH operation - O(1)
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        count++;
        cout << "Pushed " << x << " to stack" << endl;
    }

    // POP operation - O(1)
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        int x = top->data;
        top = top->next;
        delete temp;
        count--;
        cout << "Popped " << x << " from stack" << endl;
        return x;
    }

    // PEEK operation - O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get size
    int size() {
        return count;
    }
};
