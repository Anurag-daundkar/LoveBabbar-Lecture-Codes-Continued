// Diameter of a Binary Tree
// Difficulty: MediumAccuracy: 47.37%Submissions: 332K+Points: 4Average Time: 20m
// Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

// Examples:

// Input: root[] = [1, 2, 3]

// Output: 2
// Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

// Input: root[] = [5, 8, 6, 3, 7, 9]

// Output: 4
// Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

// Constraints:
// 1 ≤ number of nodes ≤ 105
// 0 ≤ node->data ≤ 105




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    
    pair<int, int> diameterfast(Node* root)
    {
        if(root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = diameterfast(root->left);
        pair<int, int> right = diameterfast(root->right);
        int middle = left.second + right.second + 1;
        
        pair<int, int> ans;
        
        ans.first = max(max(left.first, right.first), middle);
        ans.second = max(left.second, right.second)+1;
        return ans;
    }
    
    int diameter(Node* root) 
    {
        return diameterfast(root).first-1;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends