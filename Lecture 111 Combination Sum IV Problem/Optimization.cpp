//  Combination Sum IV
// Moderate
// 0/80
// Contributed by
// 48 upvotes
// Asked in companies
// Problem statement
// You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.

// Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.

// But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

// Input is given such that the answer will fit in a 32-bit integer. For Example:
// If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
// (1,1,1,1,1)
// (1,1,1,2)
// (1,2,1,1)
// (2,1,1,1)
// (1,1,2,1)
// (2,2,1)
// (1,2,2)
// (2,1,2)
// (5)
// Hence the output will be 9.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 200
// 1 <= nums[i] <= 1000
// All the elements will be unique
// 1 <= tar <= 1000

// Time limit: 1 sec
// Sample Input 1 :
// 2
// 3 5
// 1 2 5
// 2 3
// 1 2
// Sample output 1 :
// 9
// 3
// Explanation For Sample Output 1:
// For the first test case, the number of possible ways will be
// (1,1,1,1,1)
// (1,1,1,2)
// (1,2,1,1)
// (2,1,1,1)
// (1,1,2,1)
// (2,2,1)
// (1,2,2)
// (2,1,2)
// (5)

// For the second test case, the number of ways will be
// (1,1,1)
// (1,2)
// (2,1)
// Here you can see we have considered (1,2) and (2,1) in 2 different ways.
// Sample Input 2 :
// 2
// 3 4
// 12 1 3
// 2 41
// 2 34
// Sample output 2 :
// 3
// 0



In this problem, we can’t use space optimization (like using only a few variables instead of the full DP array) because the current state depends on multiple previous states, and not in a fixed pattern. For each target value i, it can depend on dp[i - num[j]] for all j, which means we need access to many different past values at once. Since these dependencies vary and aren’t limited to just recent or consecutive values, we must maintain the entire dp array, and space optimization isn’t possible here.