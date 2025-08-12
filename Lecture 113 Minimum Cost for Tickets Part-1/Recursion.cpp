// Ninja's Trip
// Moderate
// 0/80
// Contributed by
// 55 upvotes
// Asked in companies
// Problem statement
// Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
// A 1-day pass is sold for 'COST'[0] coins,
// A 7-day pass is sold for 'COST'[1] coins, and
// A 30-day  pass is sold for 'COST'[2] coins.
// The passes allow for many days of consecutive travel.
// Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
// If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 365
// 1 <= DAYS[i] <= 365

// Time Limit: 1 sec
// Sample Input 1:
// 2
// 2 
// 2 5
// 1 4 25    
// 7
// 1 3 4 5 7 8 10
// 2 7 20
// Sample Output 1:
// 2
// 11
// Explanation For sample input 1:
// For the first test case, 
// On Day 2, Ninja will buy a 1-day pass with 1 coin.
// On Day 5, Ninja will buy a 1-day pass with 1 coin.
// In total, Ninja will spend 2 coins. Hence the answer is 2.

// For the second test case,
// On Day 1, Ninja will buy a 1-day pass with 2 coins.
// On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
// On Day 10, Ninja will buy a 1-day pass with 2 coins.
// In total, Ninja will spend 11 coins. Hence the answer is 11.
// Sample Input 2:
// 2
// 6
// 1 4 6 7 8 20
// 2 7 15
// 12
// 1 2 3 4 5 6 7 8 9 10 30 31
// 2 7 15 
// Sample Output 2:
// 11
// 17





int solve(int n, vector<int> days, vector<int> cost, int Curr_day)
{
    if(Curr_day > days[n-1])
        return 0;
    
    int Curr;
    for(int i = 0 ; i < n ; i++)
    {
        if(Curr_day <= days[i])
        {
            Curr = days[i];
            break;
        }
    }

    int one = cost[0] + solve(n, days, cost, Curr+1);
    int two = cost[1] + solve(n, days, cost, Curr+7);
    int three = cost[2] + solve(n, days, cost, Curr+30);

    return min(one, min(two, three));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost, days[0]);
}
