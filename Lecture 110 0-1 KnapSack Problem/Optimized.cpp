#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0);
	vector<int> curr(maxWeight+1, 0);

	for(int i = 0 ; i <= maxWeight ; i++)
	{
		if(weight[0] <= i)
			prev[i] = value[0];
		else
			prev[i] = 0;
	}

	for(int i = 1 ; i < n ; i++)
	{
		int include = 0;
		for(int j = 0 ; j <= maxWeight ; j++)
		{
			if(weight[i] <= j)
				include = value[i] + prev[j - weight[i]];
			curr[j] = max(include, prev[j]);
		}
		prev = curr;
	}
	return prev[maxWeight];
}
