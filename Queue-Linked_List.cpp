#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class Queue
{

    // Data Members
public:
    int size;
    Node *front;
    Node *rear;

    // Data Functions
public:
    Queue()
    {
        size = 0;
        front = rear = NULL;
    }
    void push(int ele)
    {
        // If Queue is empty
        Node *temp = new Node(ele);
        if (front == NULL && rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        // If Elements are present in the queue
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
        size++;
    }
    int returnFront()
    {
        // If Queue is empty
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    int returnRear()
    {
        // If Queue is empty
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            return rear->data;
        }
    }
    void dequeue()
    {
        // If Queue is Empty
        if (front == NULL)
        {
            cout << "Nothing to Delete!" << endl;
        }
        else if (front == rear) // If only 1 Element is present in the queue
        {
            front = rear = NULL;
            free(front);
        }
        else
        {
            Node *delNode = front;
            front = front->next;
            free(delNode);
            delete (delNode);
        }
    }
};

int main()
{
    Queue obj;
    cout << "Front is " << obj.returnFront() << endl;
    cout << "Rear is " << obj.returnRear() << endl;
    cout << "----------------------------------------" << endl;

    // Pushing Elements
    obj.push(11);
    cout << "Front is " << obj.returnFront() << endl;
    cout << "Rear is " << obj.returnRear() << endl;
    cout << "----------------------------------------" << endl;

    obj.push(122);
    obj.push(125);
    obj.push(99);
    cout << "Front is " << obj.returnFront() << endl;
    cout << "Rear is " << obj.returnRear() << endl;
    cout << "----------------------------------------" << endl;

    // Popping element
    obj.dequeue();
    cout << "Front is " << obj.returnFront() << endl;
    cout << "Rear is " << obj.returnRear() << endl;
    cout << "----------------------------------------" << endl;
    return 0;
}
