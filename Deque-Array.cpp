#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

public:
    // Constructor to initialize the values
    Deque(int n)
    {
        this->size = n;
        this->arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }
    void pushFront(int val)
    {
        // Check isFull condition
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full!" << endl;
        }
        else if (front == -1) // Pushing First Element
        {
            front = rear = 0;
            arr[front] = val;
        }
        else if (front == 0 && rear != size - 1) // Maintain Cyclic Nature
        {
            front = size - 1;
            arr[front] = val;
        }
        else // Normal Nature
        {
            arr[front] = val;
            front--;
        }
    }
    void pushBack(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full!" << endl;
        }
        // case 2 when queue is empty.
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        // case 3 When queue is neither empty nor full.
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void popFront()
    {
        // Check if the queue is emtpy of not
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Emtpy" << endl;
        }
        // Only 1 Element is present
        else if (front == rear)
        {
            front = rear = -1;
        }
        // front is pointing at the last position
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Emtpy" << endl;
        }
        // Only 1 Element is present
        else if (front == rear)
        {
            front = rear = -1;
        }
        // front is pointing at the last position
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (rear == -1)
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }
};

int main()
{
    Deque obj1(5);

    // Pushing at the Front
    obj1.pushFront(7);
    obj1.pushFront(11);

    // Pushing at the back
    obj1.pushBack(99);
    cout << "Front element is " << obj1.getFront() << endl;
    cout << "Rear element is " << obj1.getRear() << endl;
    obj1.pushBack(45);
    cout << "Rear element is " << obj1.getRear() << endl;

    // Pop from front
    obj1.popFront();
    cout << "Front element is " << obj1.getFront() << endl;
    obj1.popBack();
    cout << "Rear element is " << obj1.getRear() << endl;

    return 0;
}
