#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // Inserting at front and back
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    };
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    };

    // Deleting from front and back
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    };
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail) // Traverse till second last node->> while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;

    };

    // Insert at position
    void insertAtPosition(int val, int pos)
    {
        
        if (pos < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) // Update tail if inserted at the end
        {
            tail = newNode;
        }
    };

    // Delete at position
    void deleteAtPosition(int pos)
    {
        if (pos < 0 || head == NULL)
        {
            cout << "Invalid position or List is empty" << endl;
            return;
        }

        if (pos == 0)
        {
            pop_front();
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        Node *nodeToDelete = temp->next;
        if (nodeToDelete == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        temp->next = nodeToDelete->next;

        if (nodeToDelete == tail) // Update tail if last node is deleted
        {
            tail = temp;
        }

        delete nodeToDelete;
    };

    // Search
    void search(int key)
    {
        Node *temp = head;
        int pos = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Element not found" << endl;

    };

    // Display
    void printList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List mylist;

    mylist.push_front(10);
    mylist.push_front(20);

    mylist.push_back(30);

    mylist.printList();

    mylist.pop_front();
    mylist.printList();

    mylist.pop_back();
    mylist.printList();

    mylist.insertAtPosition(40, 1);
    mylist.printList();

    mylist.deleteAtPosition(0);
    mylist.printList();
    
    mylist.search(40);
    mylist.search(100);

    return 0;
}