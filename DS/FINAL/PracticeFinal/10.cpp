/*Q1. Write a code to implement Stack Push() and Pop() operation using Linked List.*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    
public:
    Stack() {
        top = nullptr;
    }
    
    void Push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack\n";
    }
    
    void Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    int Peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.display();
    
    s.Pop();
    s.display();
    
    s.Pop();
    s.Pop();
    s.Pop(); // This should show underflow
    
    return 0;
}