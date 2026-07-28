#include <iostream>
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

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    // Display queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Test Queue
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}

