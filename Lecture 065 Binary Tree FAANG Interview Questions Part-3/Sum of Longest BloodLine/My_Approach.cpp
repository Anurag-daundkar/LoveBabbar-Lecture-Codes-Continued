// Sum of nodes on the longest path
// Difficulty: MediumAccuracy: 52.39%Submissions: 123K+Points: 4
// Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

// Examples:

// Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
 
// Output: 13
// Explanation:

// The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
// Input: root[] = [1, 2, 3, 4, 5, 6, 7]

// Output: 11
// Explanation: 

// The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
// Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

// Output: 19
// Explanation: 

// The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
// Constraints:
// 1 <= number of nodes <= 106
// 0 <= node->data <= 104

// Expected Complexities





/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root, pair<int, int> curr, pair<int, int> &max)
    {
        if(root == NULL)
            return;
        
        curr.first = curr.first + root->data;
        curr.second++;
        
        if(root->left)
            solve(root->left, curr, max);
            
        if(root->right)
            solve(root->right, curr, max);
            
        if(root->left == NULL && root->right == NULL)
        {
            if(max.second < curr.second)
                max = curr;
                
            else if(max.second == curr.second)
            {
                if(max.first < curr.first)
                    max = curr;
            }
        }
        
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int, int> answer = {0, 0};
        solve(root, {0, 0}, answer);
        return answer.first;
    }
};