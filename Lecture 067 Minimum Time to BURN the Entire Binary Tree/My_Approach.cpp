// Burning Tree
// Difficulty: HardAccuracy: 53.53%Submissions: 118K+Points: 8
// Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
// Note: The tree contains unique values.

// Examples : 

// Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
  
// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.
// Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

// Output: 5
// Explanation: Initially 10 is set to fire at 0 sec 
// At 1 sec: Node 5 catches fire.
// At 2 sec: Node 2 catches fire.
// At 3 sec: Nodes 1 and 4 catches fire.
// At 4 sec: Node 3 and 8 catches fire.
// At 5 sec: Node 7 catches fire.
// It takes 5s to burn the complete tree.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(h)



class Solution {
  public:
    void inorder(Node* root, unordered_map<Node*, Node*> &parent, Node* &targetNode, int target) {
        if(root == NULL) 
            return;

        if(root->data == target) 
            targetNode = root;

        if(root->left) 
        {
            parent[root->left] = root;
            inorder(root->left, parent, targetNode, target);
        }

        if(root->right) 
        {
            parent[root->right] = root;
            inorder(root->right, parent, targetNode, target);
        }
    }

    int solve(Node* node, unordered_map<Node*, Node*> &parent, unordered_map<Node*, bool> &visited) 
    {
        if(node == NULL) 
            return 0;

        visited[node] = true;
        int maxTime = 0;

        if(node->left && !visited[node->left])
            maxTime = max(maxTime, solve(node->left, parent, visited));

        if(node->right && !visited[node->right])
            maxTime = max(maxTime, solve(node->right, parent, visited));

        if(parent[node] && !visited[parent[node]])
            maxTime = max(maxTime, solve(parent[node], parent, visited));

        return 1 + maxTime;
    }

    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;
        unordered_map<Node*, bool> visited;
        Node* targetNode = NULL;

        parent[root] = NULL;
        inorder(root, parent, targetNode, target);

        return solve(targetNode, parent, visited) - 1;
    }
};
