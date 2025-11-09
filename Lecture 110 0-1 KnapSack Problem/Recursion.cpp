#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
	//base case
	if(index == 0)
	{
		if(weight[0] <= maxWeight)
			return value[0];
		else
			return 0;
	}

	int include = 0;
	if(weight[index] <= maxWeight)
		include = value[index] + solve(weight, value, index-1, maxWeight-weight[index]);

	int exclude = 0 + solve(weight, value, index-1, maxWeight);

	return max(include, exclude);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, n-1, maxWeight);
}
