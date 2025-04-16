#include <bits/stdc++.h> 

void dfs(int node, vector<int> &visited, unordered_map<int, list<int>> &adj, stack<int> &st)
{
    visited[node] = 1;
    for(auto i : adj[node])
    {
        if(!visited[i])
            dfs(i, visited, adj, st);
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(int i = 0 ; i < e ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }

    vector<int> visited(v, 0);
    stack<int> st;
    for(int i = 0 ; i < v ; i++)
    {
        if(!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}