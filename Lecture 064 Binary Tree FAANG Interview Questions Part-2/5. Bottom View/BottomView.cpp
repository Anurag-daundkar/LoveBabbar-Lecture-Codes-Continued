// Bottom View of Binary Tree
// Difficulty: MediumAccuracy: 54.18%Submissions: 307K+Points: 4Average Time: 45m
// Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.

// For the above tree, the output should be 5 8 34 22 25

// Examples :

// Input: root[] = [1, 3, 2]

// Output: [3 1 2]
// Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

// Thus bottom view of the binary tree will be 3 1 2.
// Input: root[] = [10, 20, 30, 40, 60]
         
// Output: [40 20 60 30]
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 105

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)



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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int, int> ans;
        
        
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        
        while(!q.empty())
        {
            pair<int, Node*> temp = q.front();
            q.pop();
            ans[temp.first] = temp.second->data;
            
            if(temp.second->left)
                q.push({temp.first - 1, temp.second->left});
            if(temp.second->right)
                q.push({temp.first + 1, temp.second->right});
        }
        
        vector<int> answer;
        for(auto i : ans)
        {
            answer.push_back(i.second);
        }
        return answer;
    }
};