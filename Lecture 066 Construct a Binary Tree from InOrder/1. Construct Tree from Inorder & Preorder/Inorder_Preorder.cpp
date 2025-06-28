// Construct Tree from Inorder & Preorder
// Difficulty: MediumAccuracy: 34.59%Submissions: 203K+Points: 4Average Time: 20m
// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

// Note: The output is written in postorder traversal.

// Examples:

// Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
// Output: [8, 7, 6, 1]
// Explanation: The tree will look like

// Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [3, 4, 1, 5, 2, 0]
// Explanation: The tree will look like

// Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
// Output: [2, 5, 4, 3, 1]
// Explanation: The tree will look like

// Constraints:
// 1 ≤ number of nodes ≤ 103
// 0 ≤ nodes -> data ≤ 103
// Both the inorder and preorder arrays contain unique values.

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)



// Class that contains the logic to build the binary tree
/*
Definition of the Node class
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
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node* buildTree2(vector<int> &inorder, vector<int> &preorder, int i, int j, int &p, unordered_map<int, int> &adj)
    {
        int size = inorder.size();
        if(i>j || p > size)
            return NULL;
        
        int data = preorder[p];
        Node* root = new Node(data);
        
        int a = adj[preorder[p]];
        p++;
        
        root->left = buildTree2(inorder, preorder, i, a-1, p, adj);
        root->right = buildTree2(inorder, preorder, a+1, j, p, adj);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int p = 0;
        unordered_map<int, int> adj;
        
        for(int i = 0 ; i < inorder.size() ; i++)
            adj[inorder[i]] = i;
            
        Node* root = buildTree2(inorder, preorder, 0, inorder.size()-1, p, adj);
        return root;
    }
};