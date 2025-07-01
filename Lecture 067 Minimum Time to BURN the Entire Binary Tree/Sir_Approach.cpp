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


/*
class Node {
  public:
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
  public:
  
    void inorder(unordered_map<Node*, Node*> &parent, Node* root, Node* &temp, int &target, unordered_map<Node*, bool> &visited)
    {
        if(root == NULL)
            return;
            
        if(root->data == target)
            temp = root;
            
        visited[root] = false;
        
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
            
        inorder(parent, root->left, temp, target, visited);
        inorder(parent, root->right, temp, target, visited);
    }
    
    int solve(unordered_map<Node*, Node*> &parent, unordered_map<Node*, bool> &visited, Node* temp)
    {
        int T = 0;
        queue<Node*> q;
        q.push(temp);
        visited[temp] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                Node* N = q.front();
                q.pop();
                if(N->left && !visited[N->left])
                {
                    q.push(N->left);
                    visited[N->left] = true;
                }
                    
                if(N->right && !visited[N->right])
                {
                    q.push(N->right);
                    visited[N->right] = true;
                }
                    
                if(parent[N] && !visited[parent[N]])
                {
                    q.push(parent[N]);
                    visited[parent[N]] = true;
                }
            }
            if(!q.empty())
                T++;
        }
        return T;
    }
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        unordered_map<Node*, bool> visited;
        
        parent[root] = NULL;
        Node* temp = NULL;
        inorder(parent, root, temp, target, visited);
        
        int T = solve(parent, visited, temp);
        return T;
    }
};