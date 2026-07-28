#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // Insert according to priority (smaller value = higher priority)
        if (!front || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << "Dequeued element: " << temp->data << " (Priority " << temp->priority << ")\n";
        delete temp;
    }

    void display() {
        if (!front) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Priority Queue: ";
        while (temp) {
            cout << "[" << temp->data << ", P:" << temp->priority << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Test Priority Queue
int main() {
    PriorityQueue pq;
    pq.enqueue(10, 3);
    pq.enqueue(20, 2);
    pq.enqueue(30, 1);
    pq.enqueue(40, 4);

    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}

