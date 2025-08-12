// Get Minimum Squares
// Difficulty: MediumAccuracy: 45.22%Submissions: 41K+Points: 4
// Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

// Examples:

// Input: n = 100
// Output: 1
// Explanation: 10 * 10 = 100
// Input: n = 6
// Output: 3
// Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
// Expected Time Complexity: O(n * sqrt(n))
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= n <= 104

// Company Tags
// AmazonMicrosoftWipro



// User function Template for C++

class Solution {
  public:
    int solve(int n, vector<int> &dp)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
            
        int ans = INT_MAX;
        for(int i = 1 ; i*i <= n ; i++)
            ans = min(ans, solve(n - i*i, dp));
        
        dp[n] = ans+1;
        
        return dp[n];
    }
  
    int MinSquares(int n) {
        
        vector<int> dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};
