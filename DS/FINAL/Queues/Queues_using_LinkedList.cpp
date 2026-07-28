#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }

};

class Queue{
    Node* head;
    Node* tail;

    public:
        Queue(){
            head = NULL;
            tail = NULL;
        }

        void push(int data){ // Insert value (Enqueue); time complexity: O(1)
            Node* newNode = new Node(data);
            
            if(empty()){
                head = newNode;
                tail = newNode;
            } else { // If queue is not empty
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop(){ // Delete value (Dequeue); time complexity: O(1)
            if(empty()){
                cout << "Queue is empty!" << endl;
                return;
            }

            Node* temp = head;
            head = head->next;
            delete temp;

            if(head == NULL){ // If queue becomes empty after pop
                tail = NULL;
            }
        }

        int front(){ // Front value
            if(empty()){
                cout << "Queue is empty!" << endl;
                return -1; // Indicating queue is empty
            }
            return head->data;
        }

        bool empty(){ // Queue is empty or not
            return head == NULL;
        }
};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    q.pop();
    q.pop();
    // Queue is empty!
    
    cout << "Front element after popping all elements: " << q.front() << endl;
    return 0;
}