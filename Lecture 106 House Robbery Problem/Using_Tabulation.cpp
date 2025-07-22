#include <bits/stdc++.h> 
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)
        return valueInHouse[0];

    vector<int> vec1;
    vector<int> vec2;
    for(int i = 0 ; i < n ; i++)
    {
        if(i != n-1)
            vec1.push_back(valueInHouse[i]);
        if(i != 0)
            vec2.push_back(valueInHouse[i]);
    }

    vector<long long int> dp(n-1, -1);
    dp[0] = vec1[0];
    dp[1] = max(vec1[0], vec1[1]);
    for(int i = 2 ; i < n-1 ; i++)
    {
        long long int included = dp[i-2] + valueInHouse[i];
        long long int excluded = dp[i-1];
        dp[i] = max(included, excluded);
    }
    long long int maxi = dp[n-2];
    dp[0] = vec2[0];
    dp[1] = max(vec2[0], vec2[1]);
    for(int i = 2 ; i < n-1 ; i++)
    {
        long long int included = dp[i-2] + valueInHouse[i+1];
        long long int excluded = dp[i-1];
        dp[i] = max(included, excluded);
    }
    maxi = max(maxi, dp[n-2]);
    return maxi;
}
