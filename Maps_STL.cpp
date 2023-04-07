#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    //! Creation
    unordered_map<string, int> u_mp;

    //! Insertion
    //* Ist method
    pair<string, int> p = make_pair("rajat", 4);
    u_mp.insert(p);

    //* 2nd method
    pair<string, int> q("hello", 5);
    u_mp.insert(q);

    //* 3rd method
    u_mp["good"] = 6;

    //! Searching
    cout << u_mp["hello"] << endl;

    //! To check size
    cout << u_mp.size() << endl;

    //! To erase
    u_mp.erase("hello");

    // ! Traversing using iterators
    unordered_map<string, int>::iterator it = u_mp.begin();
    while (it != u_mp.end())
    {
        cout << it->first << " : " << it->second << endl;
        it++;
    }
    return 0;
}
