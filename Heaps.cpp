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

    void deletion()
    {

        if (size == 0)
        {
            cout << "Nothing to delete " << endl;
            return;
        }

        // Step 1;
        arr[1] = arr[size];

        // Step 2;
        size--;

        // Step 3
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
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
    h.deletion();
    h.print();

    return 0;
}
