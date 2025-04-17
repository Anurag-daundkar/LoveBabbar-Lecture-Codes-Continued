#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    vector<int> indegree(v, 0);
    for(int i = 0 ; i < e ; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> ans;
    queue<int> q;
    for(int i = 0 ; i < v ; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        for(auto i : adj[temp])
        {
            indegree[i]--;
            if(indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}