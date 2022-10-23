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

class circularQueue
{
public:
    Node *front;
    Node *rear;

public:
    circularQueue()
    {
        this->front = NULL;
        this->rear = NULL;
    }

    void enQueue(int x)
    {
        // if first element is pushing
        Node *newNode = new Node(x);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        rear->next = front;
    }
    void deQueue()
    {
        // if Queue is empty
        if (front == NULL)
        {
            cout << "Queue is Empty, Nothing to delete!" << endl;
        }
        else if (front == rear) // Only 1 Element is Present
        {
            delete (front);
            front = rear = NULL;
        }
        else
        {
            Node *delNode = front;
            rear->next = front->next;
            front = front->next;
            delNode->next = NULL;
            delete delNode;
        }
    }
    // Return front;
    int returnFront()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty ";
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    // Return rear
    int returnRear()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty ";
            return -1;
        }
        else
        {
            return rear->data;
        }
    }
};

int main()
{
    circularQueue obj;
    cout << "| Front is " << obj.returnFront() << endl;
    cout << "| Rear is " << obj.returnRear() << endl;
    obj.deQueue();
    obj.enQueue(17);
    cout << "| Front is " << obj.returnFront() << endl;
    cout << "| Rear is " << obj.returnRear() << endl;
    obj.enQueue(171);
    obj.enQueue(161);
    obj.enQueue(181);
    obj.enQueue(191);
    cout << "| Front is " << obj.returnFront() << endl;
    cout << "| Rear is " << obj.returnRear() << endl;
    obj.deQueue();
    cout << "| Front is " << obj.returnFront() << endl;
    cout << "| Rear is " << obj.returnRear() << endl;
    return 0;
}
