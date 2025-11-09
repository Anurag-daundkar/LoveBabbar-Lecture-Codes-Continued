#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	for(int i = 0 ; i <= maxWeight ; i++)
	{
		if(weight[0] <= i)
			dp[0][i] = value[0];
		else
			dp[0][i] = 0;	
	}


	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 0 ; j <= maxWeight ; j++)
		{
			if(weight[i] <= j)
				dp[i][j] = value[i] + dp[i-1][j -weight[i]];
			else
				dp[i][j] = dp[i-1][j];

			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	return dp[n-1][maxWeight];
}
