#include <iostream>
using namespace std;

//!     Class Node
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//!     Class Stack
class Stack
{
public:
    int size;
    Node *head;

    // Constructor to initialize the values of the objects
    Stack()
    {
        size = 0;
        head = NULL;
    }

    // To get size of stack
    int getSize()
    {
        return size;
    }

    // IsEmpty
    bool isEmpty()
    {
        return (size == 0);
    }

    // To push an element;
    void push(int val)
    {
        // Create a node first
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // To pop an element
    int pop()
    {
        Node *temp = head;
        int ans = temp->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    // To get top element
    int peek()
    {
        return head->data;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Stack obj;
    obj.push(20);
    obj.push(10);
    obj.push(40);
    obj.push(60);
    obj.display();
    cout << "Peek element is "
         << obj.peek() << endl;
    cout << "Popped element is " << obj.pop() << endl;
    obj.display();
    cout << "Peek element is "
         << obj.peek() << endl;
    cout << "Size of stack is " << obj.getSize() << endl;
    cout << "Is the stack empty " << obj.isEmpty() << endl;

    return 0;
}
