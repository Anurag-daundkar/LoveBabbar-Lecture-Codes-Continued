// Right View of Binary Tree
// Difficulty: EasyAccuracy: 65.18%Submissions: 193K+Points: 2Average Time: 20m
// Given a Binary Tree, Your task is to return the values visible from Right view of it.

// Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Examples :

// Input: root = [1, 2, 3, 4, 5]
//      2_2
// Output: [1, 3, 5]
// Input: root = [1, 2, 3, 4, N, N, 5]
//      Right-view-in-binary-tree-1
// Output: [1, 3, 4, 5]
// Input: root = [10, 20, 90, 40, 60]
//      10
//     /   \
//   20     90
//  /   \
// 40  60 
// Output: [10, 90, 60]
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 0 ≤ node->data ≤ 105

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)






/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();

                if (i == levelSize-1)
                    result.push_back(current->data);

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }

        return result;
    }
};