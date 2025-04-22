// Vertical Tree Traversal
// Difficulty: MediumAccuracy: 32.87%Submissions: 200K+Points: 4Average Time: 45m
// Given a root of a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, N, N, N, 8, N, 9]
//      Vertical-Taversal-          
// Output: [[4], [2], [1, 5, 6], [3, 8], [7], [9]]
// Explanation: The below image shows the horizontal distances used to print vertical traversal starting from the leftmost level to the rightmost level.
     
// Input: root[] = [1, 2, 3, 4, 5, N, 6]
     
// Output: [[4], [2], [1, 5], [3], [6]]
// Explanation: From left to right the vertical order will be [[4], [2], [1, 5], [3], [6]]
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 105










//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

// Function to Build Tree
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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


// } Driver Code Ends

/*
// Tree Node
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
    void Traversal(Node* root, int index, map<int, list<int>> &answer)
    {
        if(root == NULL)
            return;
        
        answer[index].push_back(root->data);
        
        Traversal(root->left, index-1,  answer);
        Traversal(root->right, index+1,  answer);
    }
    
  
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, list<int>> answer;
        
        Traversal(root, 0, answer); 
        
        vector<vector<int>> result;
        for(auto i : answer)
        {
            vector<int> ans;
            for(auto j : i.second)
            {
                ans.push_back(j);
            }
            result.push_back(ans);
        }
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Solution obj;
        Node* root = buildTree(s);

        vector<vector<int>> res = obj.verticalOrder(root);
        cout << "[ ";
        for (auto& vec : res) {
            cout << "[ ";
            for (int val : vec) {
                cout << val << " ";
            }
            cout << "] ";
        }
        cout << "]" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends