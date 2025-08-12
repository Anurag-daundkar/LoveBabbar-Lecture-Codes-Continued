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
    int MinSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++)
        {
            for(int j = 1 ; j*j <= i ; j++)
                dp[i] = min(dp[i], dp[i-(j*j)]+1);
        }
        return dp[n];
    }
};
