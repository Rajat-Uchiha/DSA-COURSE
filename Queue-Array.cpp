#include <iostream>
using namespace std;

class Queue
{
    // data members
public:
    int *arr;
    int size;
    int qfront;
    int qrear;

public:
    // Constructor
    Queue(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->qfront = 0;
        this->qrear = 0;
    }

    // To push element
    void push(int data)
    {
        // if full
        if (qrear == size)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            arr[qrear] = data;
            qrear++;
        }
    }

    // To delete an element;
    int pop()
    {
        // if queue is empty
        if (qrear == size)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == qrear)
            {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }
    // front element;
    int front()
    {
        if (qrear == qfront)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    Queue obj1(5);
    obj1.push(10);
    obj1.push(20);
    obj1.push(30);
    obj1.push(40);
    obj1.push(1212);
    obj1.push(12122);
    obj1.pop();
    cout << "Front element is " << obj1.front() << endl;

    return 0;
}
