#include<bits/stdc++.h>
using namespace std;

#define max_size 100
int queue_array[max_size];
int front = -1, rear = -1;

void push(int value){
    if(rear == max_size - 1){
        cout << "OVERFLOW" << endl;
        return;
    } 
    if(front == -1) front = 0; // Initialize front when first element is added
    rear++;
    queue_array[rear] = value;
}

void pop(){
    if(front == -1){ 
        cout << "UNDERFLOW" << endl;
        return;
    }
    front++;
}

int peek(){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return -1; // Indicating empty queue
    }
    return queue_array[front];
}

int main(){
    push(10);
    push(20);
    push(30);

    cout << "Front element: " << peek() << endl; // Output: 10

    pop();
    cout << "Front element after pop: " << peek() << endl; // Output: 20

    pop();
    cout << "Front element after pop: " << peek() << endl; // Output: 30

    pop();
    cout << "Front element after pop: " << peek() << endl; // Output: Queue is empty

    return 0;
}