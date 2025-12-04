#include<bits/stdc++.h>
using namespace std;

#define max_size 5
int queue_array[max_size];
int front = -1, rear = -1;

void push(int value){
    if((front == 0 && rear == max_size - 1) || (front == rear +1)){
        cout << "OVERFLOW" << endl;
        return;
    } else if(front == -1){
        front++;
        rear++;
    } else if(rear == max_size -1){
        rear = 0;
    } else
    rear++;

    queue_array[rear] = value;
}

void pop(){
    if(front == -1){ 
        cout << "UNDERFLOW" << endl;
        return;
    }
    if(front == rear){ // Queue has only one element
        front = -1;
        rear = -1;
    } else if(front == max_size -1){
        front = 0;
    } else
    front++;
}

int peek(){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return -1; // Indicating empty queue
    }
    return queue_array[front];
}
void showQueue(){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    if(rear >= front){
        for(int i = front; i <= rear; i++){
            cout << queue_array[i] << " ";
        }
    } else {
        for(int i = front; i < max_size; i++){
            cout << queue_array[i] << " ";
        }
        for(int i = 0; i <= rear; i++){
            cout << queue_array[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    // push(60); // This should show OVERFLOW

    pop();

    push(60); // This should work due to circular nature

    cout << rear << " " << front << endl; // To check position after wrap around
    cout << "Front element: " << peek() << endl; // Output: 10

    showQueue(); // Display current queue

    pop();
    cout << "Front element after pop: " << peek() << endl; // Output: 20

    pop();
    cout << "Front element after pop: " << peek() << endl; // Output: 30

    pop();
    cout << "Front element after pop: " << peek() << endl; // Output: Queue is empty

    push(70);
    push(80);

    showQueue(); // Display current queue

    return 0;
}