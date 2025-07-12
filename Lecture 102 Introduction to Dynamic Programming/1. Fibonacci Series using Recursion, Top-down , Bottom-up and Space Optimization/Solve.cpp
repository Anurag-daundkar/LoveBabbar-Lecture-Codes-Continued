// 1. Using Recursion

#include<iostream>
using namespace std;

int solve(int n)
{
    if(n == 0 || n == 1)
        return n;
    
    int ans = solve(n-1) + solve(n-2);
    return ans;
}

int main()
{
    cout << "Enter the position n to get the nth Fibonacci number (0-based): ";
    int n;
    cin >> n;

    cout << solve(n) << endl;
}


// -----------------------------------------------------------------------------------------------------

/*
// Using Top Down Approach

#include<iostream>
#include<vector>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if(n == 0 || n == 1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];

    dp[n] = solve(n-1, dp) + solve(n-2, dp);
    return dp[n];
}

int main()
{
    cout << "Enter the position n to get the nth Fibonacci number (0-based): ";
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);

    cout << solve(n, dp) << endl;
}
*/

// -----------------------------------------------------------------------------------------------------

/*
// Using Bottom Up Approach

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Enter the position n to get the nth Fibonacci number (0-based): ";
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);

    dp[0] = 0;
    dp[1] = 1;

    if(n == 0 || n == 1)
        cout << 0;
    else
    {
        for(int i = 2 ; i <= n ; i++)
            dp[i] = dp[i-1] + dp[i-2];
    }
        cout << dp[n] << endl;
}
*/


// ----------------------------------------------------------------------------------------------

/*
// Using Space Optimization

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Enter the position n to get the nth Fibonacci number (0-based): ";
    int n;
    cin >> n;

    if(n == 0 || n== 1)
        cout << n;
    else
    {
        int prev1 = 0; 
        int prev2 = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            int temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }
        cout << prev2 << endl;
    }       
}
*/