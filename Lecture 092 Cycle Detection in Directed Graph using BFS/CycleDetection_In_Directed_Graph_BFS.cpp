#include<unordered_map>
#include<list>
#include<vector>
#include<queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
  vector<int> indegree(n, 0);
  unordered_map<int, list<int>> adj;
  for(int i = 0 ; i < edges.size() ; i++)
  {
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adj[u].push_back(v);
    indegree[v]++;
  }  

  queue<int> q;
  for(int i = 0 ; i < n ; i++)
  {
    if(indegree[i] == 0)
    {
      q.push(i);
    }
  }

  int ans = 0;

  while(!q.empty())
  {
    int temp = q.front();
    q.pop();
    ans++;

    for(auto i : adj[temp])
    {
      indegree[i]--;
      if(indegree[i] == 0)
      {
        q.push(i);
      }
    }
  }
  if(ans == n)
    return 0;
  else
    return 1;
}