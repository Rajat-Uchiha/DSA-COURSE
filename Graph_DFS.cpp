#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

//! Adjacency list
unordered_map<int, list<int>> adj;
class Graph
{

public:
    //*Function to create adjacency list
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    //*Function to print adjacency list
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

//! DFS

void DFS_traversal(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = 1;

    for (auto i : adj[node])
    {

        if (!visited[i])
        {
            DFS_traversal(i, adj, visited, ans);
        }
    }
}

int main()
{
    int nodes;
    int edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    //*Create instance of the Graph
    cout << "Enter the edges of the nodes " << endl;
    Graph g;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    cout << endl
         << "Printing adjacency list" << endl;
    g.printList();

    //! DFS---------------Traversal
    vector<int> ans;

    //*Creation of visited datastructure;
    unordered_map<int, bool> visited;

    for (int node = 1; node <= nodes; node++)
    {
        if (!visited[node])
        {
            DFS_traversal(node, adj, visited, ans);
        }
    }

    //! Printing DFS traversal
    cout << endl
         << "DFS Traversal: " << endl;
    for (auto ele : ans)
    {
        cout << ele << ", ";
    }

    return 0;
}
