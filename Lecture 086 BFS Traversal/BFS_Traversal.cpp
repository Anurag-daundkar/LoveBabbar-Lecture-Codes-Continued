#include<queue>
#include<vector>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> visited(n,0);
    queue<int> q;
    vector<int> ans;
    
    q.push(0);
    visited[0] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        ans.push_back(node);

        for(auto i : adj[node])
        {
            if(visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}
