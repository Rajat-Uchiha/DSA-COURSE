#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    cout << "The top element is: " << st.top() << endl;
    cout << "Is stack empty? " << st.empty() << endl;
    cout << "The element present is stack are: " << endl;
    while (!st.empty())
    {
        cout << st.top() <<" ";
        st.pop();
    }
    return 0;
}
