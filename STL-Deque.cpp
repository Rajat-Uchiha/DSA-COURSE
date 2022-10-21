#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Creating a Dequeue of type int having name as dq;
    deque<int> dq;

    // pushing from front
    dq.push_front(12);
    dq.push_front(14);

    // pushing from back
    dq.push_back(11);
    dq.push_back(13);

    // Front and Back Element of Queue;
    cout << "Front element is: " << dq.front() << endl;
    cout << "Back element is: " << dq.back() << endl;

    // Pop from front
    dq.pop_front();

    // Pop from back
    dq.pop_back();

    // Front and Back Element of Queue;
    cout << "Front element is: " << dq.front() << endl;
    cout << "Back element is: " << dq.back() << endl;

    // is Empty
    cout << "Is Deque empty: " << dq.empty() << endl;

    return 0;
}
