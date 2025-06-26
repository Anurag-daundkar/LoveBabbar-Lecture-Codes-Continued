// Difficulty: MediumAccuracy: 52.85%Submissions: 196K+Points: 4Average Time: 20m
// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Examples:

// Input: root = [1,2,3,4,5,6,7], n1 = 5 , n2 = 6

      
// Output: 1
// Explanation: LCA of 5 and 6 is 1.
// Input: root = [5, 2, N, 3, 4], n1 = 3 , n2 = 4 

//            5    
//           /    
//          2  
//         / \  
//        3   4
// Output: 2
// Explanation: LCA of 3 and 4 is 2. 
// Input: root = [5, 2, N, 3, 4], n1 = 5 , n2 = 4 

//            5    
//           /    
//          2  
//         / \  
//        3   4
// Output: 5
// Explanation: LCA of 5 and 4 is 5. 
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)




/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        if(root == NULL)
            return NULL;
            
        if(root->data == n1 || root->data == n2)
            return root;
            
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
            
        if(left == NULL && right == NULL)
            return NULL;
        else if(left == NULL && right != NULL)
            return right;
        else if(left != NULL && right == NULL)
            return left;
        else if(left != NULL && right != NULL)
            return root;
            
    }
};