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






// User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    private:
    void longestSum(int lenght,int sum, pair<int, int> &ans, Node* root){
        // base case
        if(root==NULL)
        {
            if(lenght>ans.first)
            {
            ans.first=lenght;
            ans.second=sum;
            }
            return ;
        }
        
        lenght++;
        sum=sum+root->data;
        
        longestSum(lenght, sum, ans, root->left);
        longestSum(lenght, sum, ans, root->right);
        
        if(root->left==NULL && root->right==NULL)
        {
            if(lenght>=ans.first)
            {
                if(lenght==ans.first && sum>ans.second)
                {
                    ans.second=sum;
                }
            }
            return;
        }

    }
    
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        int lenght=0,sum=0;
        pair<int,int> ans=make_pair(0,0);
        
        longestSum(lenght,sum,ans,root);
        
        return ans.second;
    }
};