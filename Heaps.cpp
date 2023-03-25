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

// Heapify (Max heap)
void heapify(vector<int> &arr, int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }

    // If index is updated
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

void heapSort(vector<int> &arr, int size)
{
    int n = size;
    while (n > 1)
    {
        swap(arr[1], arr[n]);
        n--;

        heapify(arr, size, 1);
    }
}

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
    cout << endl
         << "-----------------------------" << endl;

    // ! HEAPIFY FUNCTION
    vector<int> arr = {-1, 54, 53, 55, 52, 50};

    int size = arr.size();
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
