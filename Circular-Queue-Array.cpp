#include <iostream>
using namespace std;

class CircularArr
{
public:
    int *arr;
    int size;
    int qFront;
    int qRear;

public:
    CircularArr(int size)
    {
        this->size = size;
        this->arr = new int[size];
        qFront = -1;
        qRear = -1;
    }
    // To push element
    void push(int data)
    {
        //  Case 1 when queue is full.
        if ((qFront == 0 && qRear == size - 1) || (qRear == (qFront - 1) % (size - 1)))
        {
            cout << "Queue is full!" << endl;
        }
        // case 2 when queue is empty.
        else if (qFront == -1)
        {
            qFront = 0;
            qRear = 0;
            arr[qRear] = data;
        }
        // case 3 When queue is neither empty nor full.
        else if (qFront != 0 && qRear == size - 1)
        {
            qRear = 0;
            arr[qRear] = data;
        }
        else
        {
            qRear++;
            arr[qRear] = data;
        }
    }

    int front()
    {
        if (qRear == -1 && qFront == -1)
        {
            return -1;
        }
        else
        {
            int ans = arr[qFront];
            return ans;
        }
    }

    int pop()
    {
        int ans;
        // Check if the queue is emtpy of not
        if (qFront == -1 && qRear == -1)
        {
            ans = -1;
        }
        // Only 1 Element is present
        else if (qFront == qRear)
        {
            ans = arr[qFront];
            qFront = qRear = -1;
        }
        // front is pointing at the last position
        else if (qFront == size - 1)
        {
            ans = arr[qFront];
            qFront = 0;
        }
        else
        {
            ans = arr[qFront];
            qFront++;
        }
        return ans;
    }
};

int main()
{
    CircularArr obj1(5);
    obj1.push(4);
    obj1.push(6);
    obj1.push(8);
    obj1.push(9);
    obj1.push(19);
    cout << "Popped element is " << obj1.pop() << endl;
    cout << "Front element is " << obj1.front() << endl;
    obj1.push(1);
    return 0;
}
