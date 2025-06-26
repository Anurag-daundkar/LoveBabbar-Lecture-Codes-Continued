// Kth Ancestor in a Tree
// Difficulty: MediumAccuracy: 35.06%Submissions: 124K+Points: 4
// Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// Examples :

// Input: k = 2, node = 4

// Output: 1
// Explanation:
// Since, k is 2 and node is 4, so we first need to locate the node and look k times its ancestors. Here in this Case node 4 has 1 as his 2nd Ancestor aka the root of the tree.
// Input: k=1, node=3    

// Output: 1
// Explanation: k=1 and node=3 ,kth ancestor of node 3 is 1.
// Constraints:
// 1<=n<=105
// 1<= k <= 100
// 1 <= Node.data <= n

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)


/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    void solve(Node *root, int k, int node, vector<int> &vec, bool &check, int &ans)
    {
        if(root == NULL)
            return;
        
        vec.push_back(root->data);
        if(root->data == node)
        {
            check = true;
            int size = vec.size();
            size = (size-1)-k;
            
            if(size >= 0)
                ans = vec[size];
            else 
                ans = -1;
        }
        
        if(!check)
            solve(root->left, k, node, vec, check, ans);
        
        if(!check)
            solve(root->right, k, node, vec, check, ans);
        
        vec.pop_back();
    }
    int kthAncestor(Node *root, int k, int node) {
        int ans = -1;
        vector<int> vec;
        bool check = false;
        
        solve(root, k, node, vec, check, ans);
        return ans;
    }
};
