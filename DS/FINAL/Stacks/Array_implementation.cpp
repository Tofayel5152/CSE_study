#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack
{
public:
    int top = -1;
    int arr[MAX];

    void push(int x)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    void topElement()
    {
        if (top < 0)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Top Element: " << arr[top] << endl;
    }

    bool isEmpty()
    {
        return top < 0;
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    s.topElement();
    cout << "Stack size: " << s.size() << endl;

    s.pop();
    s.display();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}