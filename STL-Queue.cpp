#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // CREATE a queue using STL;
    queue<int> q;
    q.push(13);
    q.push(7);
    q.push(83);
    q.pop();
    cout << "Size of queue:" << q.size() << endl;
    cout << "Front of queue:" << q.front() << endl; // garbage values if queue is empty
    cout << "Is queue empty:" << q.empty() << endl;
    return 0;
}
