#include <bits/stdc++.h>
using namespace std;

class Heap
{
    // Data members
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        this->size = 0;
    }

    // Max heap insertion
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Verify
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // To print all the elements
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;
    h.insert(5);
    h.insert(11);
    h.insert(4);
    h.insert(36);
    h.insert(1);
    h.print();

    return 0;
}
