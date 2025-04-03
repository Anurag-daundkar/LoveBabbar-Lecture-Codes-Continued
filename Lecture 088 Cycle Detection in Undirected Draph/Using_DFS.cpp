// Sir Approach

#include<unordered_map>
#include<list>

bool dfs(int node, unordered_map<int, list<int>> adj, vector<int> &visited, int parent)
{
    visited[node] = 1;
    for(auto neighbour : adj[node])
    {
        if(visited[neighbour] == 0)
        {
            bool cycle_detected = dfs(neighbour, adj, visited, node);

            if(cycle_detected)
                return true;
        }
        else if(parent != neighbour)
        {
            return true;
        }
    }
    return false;
} 

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Creating Adj list
    unordered_map<int, list<int>> adj;
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> visited(n, 0);
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i, adj, visited, -1))
            {
                return "Yes";
            }
        }     
    }
    return "No";
}


// Some changes

// #include<unordered_map>
// #include<list>

// bool dfs(int node, unordered_map<int, list<int>> adj, vector<int> &visited, unordered_map<int, int> &parent)
// {
//     for(auto neighbour : adj[node])
//     {
//         if(visited[neighbour] == 0)
//         {
//             parent[neighbour] = node;
//             visited[neighbour] = 1;
//             bool cycle_detected = dfs(neighbour, adj, visited, parent);

//             if(cycle_detected)
//                 return true;
//         }
//         else if(parent[node] != neighbour)
//         {
//             return true;
//         }
//     }
//     return false;
// } 

// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     //Creating Adj list
//     unordered_map<int, list<int>> adj;
//     for(int i = 0 ; i < edges.size() ; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u-1].push_back(v-1);
//         adj[v-1].push_back(u-1);
//     }

//     vector<int> visited(n, 0);
//     unordered_map<int, int> parent;
//     string ans = "No";
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(visited[i] == 0)
//         {
//             parent[i] = -1;
//             visited[i] = 1;
//             if(dfs(i, adj, visited, parent))
//             {
//                 ans = "Yes";
//                 return ans;
//             }
//         }     
//     }
//     return ans;
// }
