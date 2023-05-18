#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<int, list<int>> adj;
class graph
{
public:
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

//! BFS
vector<int> BFS_Traversal(vector<int> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int currNode)
{
    queue<int> q;
    visited[currNode] = 1;
    q.push(currNode);

    while (!q.empty())
    {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes ";
    cin >> n;

    int m;
    cout << "Enter the number of edges ";
    cin >> m;

    // *Create an instace of a graph
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        //* Creating an undirected graph
        g.addEdge(u, v, 0);
    }

    //* Print graph
    cout << endl
         << "Printing adjancency list: " << endl;
    g.printList();

    //! BFS-------------------------- traversal------------------------------

    //*Stores the answer
    vector<int> BFS;

    //* Create the visited datastructure
    unordered_map<int, bool> visited;

    //*Traverse all the nodes ( nodes starting from 0 to n-1)
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS_Traversal(BFS, adj, visited, i);
        }
    }

    //* Print the BFS
    cout << endl
         << "BFS Traversal can be shown as: " << endl;
    for (auto i : BFS)
    {
        cout << i << " ";
    }

    return 0;
}
