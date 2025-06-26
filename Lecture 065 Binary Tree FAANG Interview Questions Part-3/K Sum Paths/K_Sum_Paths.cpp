// K Sum Paths
// Difficulty: MediumAccuracy: 44.73%Submissions: 128K+Points: 4
// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

// Examples:

// Input: k = 7   

// Output: 3
// Explanation: The following paths sum to k 
 
// Input: k = 3

// Output: 2 
// Explanation: Path 1 : 1 -> 2 (Sum = 3) Path 2 : 3 (Sum = 3)

// Constraints:
// 1 ≤ number of nodes ≤ 104
// -100 ≤ node value ≤ 100
// -109 ≤ k ≤ 109

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(h)




// User function template for C++
 
/*
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    
    private:
    void solve(Node* root , int k , int &count , vector<int> q)
    {
        //base case
        if(root==NULL){
            return ;
        }
        
        q.push_back(root->data);
        
        //go down and then after going down compare them with K
        solve(root->left , k , count , q);
        solve(root->right , k , count , q);
        
        int sum=0;
        int size=q.size();
        for(int i=size-1 ; i>=0 ; i--)
        {
            sum = sum + q[i];
            if(k==sum)
            {
                count=count+1;
            }
        }
        
        q.pop_back();
        
    }
    
  public:
    int sumK(Node *root, int k) {
        int count = 0;
        vector<int> q;
        
        solve(root , k , count , q);
        return count;
    }
};