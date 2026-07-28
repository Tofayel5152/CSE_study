#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (!front) {
            cout << "Deque is empty!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front)
            front->prev = nullptr;
        else
            rear = nullptr;

        cout << "Deleted from front: " << temp->data << endl;
        delete temp;
    }

    void deleteRear() {
        if (!rear) {
            cout << "Deque is empty!\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear)
            rear->next = nullptr;
        else
            front = nullptr;

        cout << "Deleted from rear: " << temp->data << endl;
        delete temp;
    }

    void display() {
        Node* temp = front;
        cout << "Deque: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Test Deque
int main() {
    Deque dq;
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    dq.display();

    return 0;
}
