// Identical Trees
// Difficulty: EasyAccuracy: 50.01%Submissions: 281K+Points: 2Average Time: 15m
// Given two binary trees with their root nodes r1 and r2, return true if both of them are identical, otherwise, false.

// Examples:

// Input:
//     1          1
//    /   \       /   \
//   2     3    2    3
// Output: true
// Explanation: 
// There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
// Input:
//     1         1
//    /   \      /  \
//   2     3   3   2
// Output: false
// Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
// Input:
//     1   1
//    /      \
//   2        2
// Output: false
// Explanation: Although both trees have the same node values (1 and 2), they are arranged differently, making the trees non-identical.
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 109



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends
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
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        
        //base case
        if(r1 == NULL && r2 == NULL)
            return true;
            
        else if(r1 == NULL && r2 != NULL)
            return false;
        
        else if(r1 != NULL && r2 == NULL)
            return false;
            
        else
        {
            if(r1->data == r2->data)
            {
                bool left = isIdentical(r1->left, r2->left);
                bool right = isIdentical(r1->right, r2->right);
                
                return (left && right);
            }
            else 
                return false;
        }
        
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
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

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str, str1;
        getline(cin, str);
        Node *rootA = buildTree(str);
        getline(cin, str1);
        Node *rootB = buildTree(str1);
        Solution ob;
        if (ob.isIdentical(rootA, rootB)) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends