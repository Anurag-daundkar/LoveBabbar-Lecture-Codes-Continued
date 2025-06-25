// Left View of Binary Tree
// Difficulty: EasyAccuracy: 33.74%Submissions: 564K+Points: 2Average Time: 20m
// You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// If the tree is empty, return an empty list.

// Examples :

// Input: root[] = [1, 2, 3, 4, 5, N, N]

// Output: [1, 2, 4]
// Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

// Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

// Output: [1, 2, 4, 5]
// Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

// Input: root[] = [N]
// Output: []
// Constraints:
// 0 <= number of nodes <= 106
// 0 <= node -> data <= 105

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
    vector<int> leftView(Node *root) {
        // code here
        vector<int> check;
        if(root == NULL)
            return check;
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp != NULL)
            {
                check.push_back(temp->data);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            else
            {
                ans.push_back(check);
                check.clear();
                if(!q.empty())
                    q.push(NULL);
            }
        }
        
        check.clear();
        for(int i = 0 ; i < ans.size() ; i++)
        {
            int size = ans[i].size();
            check.push_back(ans[i][0]);
        }
            
        return check;
    }
};