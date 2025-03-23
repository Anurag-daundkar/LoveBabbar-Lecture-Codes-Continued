// Balanced Tree Check
// Difficulty: EasyAccuracy: 43.15%Submissions: 329K+Points: 2Average Time: 20m
// Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

// Examples:

// Input: root[] = [10, 20, 30, 40, 60]

   
// Output: true
// Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.
// Input: root[] = [1, 2, 3, 4, N, N, N, 5]
   
// Output: false
// Explanation: The height difference between the left and right subtrees at node 2 is 2, which exceeds 1. Hence, the tree is not balanced.
// Input: root[] = [1, 2, N, N, 3]
   
// Output: false
// Explanation: The height difference between the left and right subtrees at node 1 is 2, which exceeds 1. Hence, the tree is not balanced.
// Constraints:
// 0 <= number of nodes <= 5000
// - 104 <= node->data <= 104





//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build a tree from a string representation
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N')
        return nullptr;

    vector<string> nodeValues;
    istringstream iss(str);
    for (string s; iss >> s;)
        nodeValues.push_back(s);

    Node* root = new Node(stoi(nodeValues[0]));
    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (!nodeQueue.empty() && i < nodeValues.size()) {
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        string leftValue = nodeValues[i++];
        if (leftValue != "N") {
            currentNode->left = new Node(stoi(leftValue));
            nodeQueue.push(currentNode->left);
        }

        if (i >= nodeValues.size())
            break;

        string rightValue = nodeValues[i++];
        if (rightValue != "N") {
            currentNode->right = new Node(stoi(rightValue));
            nodeQueue.push(currentNode->right);
        }
    }

    return root;
}


// } Driver Code Ends

/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    pair<bool, int> Balanced(Node* root)
    {
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<bool, int> left = Balanced(root->left);
        pair<bool, int> right = Balanced(root->right);
        
        bool check1 = left.first && right.first; 
        int check = left.second - right.second;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(check1 && (check == 0 || check == 1 || check == -1))
        {
            ans.first = true;
            return ans;
        }
        else
        {
            ans.first = false;
            return ans;
        }
    }
    
    bool isBalanced(Node* root)
    {
       return Balanced(root).first;
    }
};



//{ Driver Code Starts.

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (testCases--) {
        string treeInput;
        getline(cin, treeInput);

        Node* root = buildTree(treeInput);
        Solution solution;
        bool result = solution.isBalanced(root);

        // Output "true" or "false"
        cout << (result ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends