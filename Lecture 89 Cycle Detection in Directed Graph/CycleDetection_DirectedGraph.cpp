#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>

bool Solve(int node, unordered_map<int, list<int>> &adj, vector<int> &visited, vector<int> &dfsVisited)
{
  visited[node] = 1;
  dfsVisited[node] = 1;
  for(auto i : adj[node])
  {
    if(visited[i] == 0)
    {
      bool cycled = Solve(i, adj, visited, dfsVisited);
      if(cycled)
        return true;
    }
    
    else if(dfsVisited[i] == 1)
      return true;
  }
  dfsVisited[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
  //creating an adj list
  unordered_map<int, list<int>> adj;
  for(int i = 0 ; i < edges.size() ; i++)
  {
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adj[u].push_back(v);
  }

  vector<int> visited(n, 0);
  vector<int> dfsVisited(n, 0);
  for(int node = 0 ; node < n ; node++)
  {
    if(visited[node] == 0)
    {
      bool Cycle = Solve(node, adj, visited, dfsVisited);
      if(Cycle)
        return 1;
    }
  }
  return 0;
  
}