// Top View of Binary Tree
// Difficulty: MediumAccuracy: 38.43%Submissions: 386K+Points: 4Average Time: 45m
// You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note: 

// Return the nodes from the leftmost node to the rightmost node.
// If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
// Examples:

// Input: root[] = [1, 2, 3] 
 
// Output: [2, 1, 3]
// Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 
// Output: [40, 20, 10, 30, 100]
// Explanation: The root 10 is visible.
// On the left, 40 is the leftmost node and visible, followed by 20.
// On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
// Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
//        1
//      /   \
//     2     3
//      \   
//       4
//        \
//         5
//          \
//           6
// Output: [2, 1, 3, 6]
// Explanation: Node 1 is the root and visible.
// Node 2 is the left child and visible from the left side.
// Node 3 is the right child and visible from the right side.
// Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// Expected Complexities






/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int, list<int>> ans;
        queue<pair<int, Node*>> q;
        
        q.push({0, root});

        while(!q.empty())
        {
            pair<int, Node*> temp = q.front();
            q.pop();
            ans[temp.first].push_back(temp.second->data);
            
            if(temp.second->left)
                q.push({temp.first - 1, temp.second->left});
            if(temp.second->right)
                q.push({temp.first + 1, temp.second->right});
        }
        vector<int> answer;
        for(auto i : ans)
        {
            for(auto j : i.second)
            {
                answer.push_back(j);
                break;
            }
        }
        return answer;
    }
};