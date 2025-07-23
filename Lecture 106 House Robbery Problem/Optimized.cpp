#include <bits/stdc++.h> 
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 0) 
        return 0;
    if(n == 1) 
        return valueInHouse[0];
    if(n == 2) 
        return max(valueInHouse[0], valueInHouse[1]);

    long long int prev2 = valueInHouse[0];
    long long int prev1 = max(valueInHouse[0], valueInHouse[1]);

    long long int second = valueInHouse[1];
    long long int first = max(valueInHouse[1], valueInHouse[2]);

    for(int i = 2 ; i < n-1 ; i++)
    {
        long long int included = prev2 + valueInHouse[i];
        long long int excluded = prev1;
        prev2 = prev1;
        prev1 = max(included, excluded);

        long long int included2 = second + valueInHouse[i+1];
        long long int excluded2 = first;
        second = first;
        first = max(included2, excluded2);
    }
    return max(first, prev1);
}
