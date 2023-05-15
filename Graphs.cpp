#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class graph
{

public:
    unordered_map<int, list<int>> adj;

    //! To add an edge into the graph
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 ->undirected graph
        // direction = 1 ->directed graph

        //* Create an edge from u to v;

        adj[u].push_back(v);

        if (direction == false)
        {
            adj[v].push_back(u);
        }
    }

    //! To print the adj list
    void printList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto ele : i.second)
            {
                cout << ele << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int n;
    cout << "Enter the number of nodes ";
    cin >> n;

    int m;
    cout << "Enter the number of edges ";
    cin >> m;

    // Create an instace of a graph
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        //* Creating an undirected graph
        g.addEdge(u, v, 0);
    }

    //* Print graph
    g.printList();

    return 0;
}
