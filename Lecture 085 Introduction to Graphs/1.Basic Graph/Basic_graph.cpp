#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if(!direction)
        {
            adj[v].push_back(u);
        }
    }

    void print()
    {
        for(auto i : adj)
        {
            cout << i.first << " -> ";
            for(auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    int vertices;
    int edges;
    cout << "Enter Vertices and Edges " << endl;
    cin >> vertices >> edges;

    cout << "Enter edges " << endl;
    for(int i = 0 ; i < edges ; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v, 0);
    }
    g.print();
}