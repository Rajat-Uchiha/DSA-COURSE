#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "greekGood";
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }
    cout << st.size()<<endl;
    string ans = "";
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    cout << ans << endl;

    return 0;
}
