
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, list<int>> adj;
	for(int i = 0 ; i < edges.size() ; i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u); 
	}

	vector<int> visited(n+1, 0);
	vector<int> parent(n+1, 0);

	queue<int> q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;

	while(!q.empty())
	{
		int temp = q.front();
		q.pop();

		for(auto i : adj[temp])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i] = 1;
				parent[i] = temp;
			}
		}
	}

	vector<int> ans;
	int Last = t;
	ans.push_back(Last);

	while(Last != s)
	{
		Last = parent[Last];
		ans.push_back(Last);
	}

	reverse(ans.begin(), ans.end());
	return ans;


}
