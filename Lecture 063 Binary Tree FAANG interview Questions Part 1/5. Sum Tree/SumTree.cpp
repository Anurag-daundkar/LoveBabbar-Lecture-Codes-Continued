// Sum Tree
// Difficulty: MediumAccuracy: 37.17%Submissions: 273K+Points: 4
// Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

// Examples:

// Input:
//     3
//   /   \    
//  1     2
// Output: true
// Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
// Input:
//           10
//         /    \
//       20      30
//     /   \ 
//    10    10
// Output: false
// Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
// Input:
//    25
//   /   \    
//  9     15
// Output: false
// Constraints:
// 2 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105




/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    bool isSumTree(Node* root) {
        // Your code here
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        
        bool left = isSumTree(root->left);
        bool right = isSumTree(root->right);
        if(left && right)
        {
            int ans = 0;
            if(root->left)
                ans = ans + root->left->data;
            if(root->right)
                ans = ans + root->right->data;
        
            if(ans == root->data)
            {
                root->data = ans*2;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
};