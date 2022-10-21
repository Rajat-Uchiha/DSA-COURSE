#include <iostream>
using namespace std;

class Stack
{

    // data members
public:
    int *arr; // to store elements
    int size; // to store the size of the stack
    int top;  // to keep the track of the index at which we are going to push or pop

public:
    // Constructor to initialize the values
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // To push an element
    void push(int ele)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = ele;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    // To pop an element
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            exit(1);
        }
        else
        {
            int ans = arr[top];
            top--;
        }
    }

    // To get the top or the peek element
    int peek()
    {
        if (top == -1 || top >= size)
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};

int main()
{
    // Creating object of class stack
    Stack obj(5);
    obj.push(44);
    obj.push(41);
    obj.push(49);
    obj.push(467);
    obj.push(1313);
    // obj.push(2141);
    obj.pop();
    cout << obj.peek() << endl;
}