#include<unordered_map>
#include<queue>
#include<list>

bool cycle(int src, unordered_map<int, list<int>> adj, vector<int> &visited)
{
    unordered_map<int,int> parent;
    parent[src] = -1;

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto i : adj[frontNode])
        {
            if(visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
            else if(parent[frontNode] != i)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //creating adj list
    unordered_map<int, list<int>> adj;
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> visited(n, 0);
    unordered_map<int, int> parent;
    string ans = "No";
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == 0)
        {
            if(cycle(i, adj, visited))
            {
                ans = "Yes";  
                return ans; 
            }
        }
    }
    return ans;

}
