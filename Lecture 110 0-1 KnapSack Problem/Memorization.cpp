#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
	//base case
	if(index == 0)
	{
		if(weight[0] <= maxWeight)
			return value[0];
		else
			return 0;
	}

	if(dp[index][maxWeight] != -1)
		return dp[index][maxWeight];
		
	int include = 0;
	if(weight[index] <= maxWeight)
		include = value[index] + solve(weight, value, index-1, maxWeight-weight[index], dp);

	int exclude = 0 + solve(weight, value, index-1, maxWeight, dp);

	dp[index][maxWeight] = max(include, exclude);
	return dp[index][maxWeight];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
}
