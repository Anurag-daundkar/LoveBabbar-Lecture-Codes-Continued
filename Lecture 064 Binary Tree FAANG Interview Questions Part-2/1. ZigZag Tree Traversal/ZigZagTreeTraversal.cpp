// ZigZag Tree Traversal
// Difficulty: MediumAccuracy: 54.05%Submissions: 174K+Points: 4Average Time: 30m
// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
// In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

// Examples:

// Input:
//         1
//       /   \
//      2      3
//     / \    /  \
//    4   5  6    7
// Output: [1, 3, 2, 4, 5, 6, 7]
// Explanation:
// For level 1 going left to right, we get traversal as {1}.
// For level 2 going right to left, we get traversal as {3,2}.
// For level 3 going left to right, we get traversal as {4,5,6,7}.
// Merging all this traversals in single array we get {1,3,2,4,5,6,7}.
// Input:
//           7
//         /   \
//        9     7
//      /  \   /   
//     8   8  6     
//    /  \
//   10   9 
// Output: [7, 7, 9, 8, 8, 6, 9, 10] 
// Explanation:
// For level 1 going left to right, we get traversal as {7}.
// For level 2 going right to left, we get traversal as {7,9}.
// For level 3 going left to right, we get traversal as {8,8,6}.
// For level 4 going right to left, we get traversal as {9,10}.
// Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.
// Input:
//           5
//         /   \
//        1     9
//       / \   / \
//      3   2 8   4

// Output: [5, 9, 1, 3, 2, 8, 4]
// Explanation:
// For level 1 going left to right, we get traversal as {5}.
// For level 2 going right to left, we get traversal as {9,1}.
// For level 3 going left to right, we get traversal as {3,2,8,4}.
// Merging all this traversals in single array we get {5,9,1,3,2,8,4}.
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 105







//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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

//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> answer;
    	bool LeftToRight = true;
    	queue<Node*> q;
    	q.push(root);
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int> ans(size);
    	    for(int i = 0 ; i < size ; i++)
    	    {
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        int index;
    	        if(LeftToRight)
    	            index = i;
    	        else
    	            index = size - i - 1;
    	            
    	        ans[index] = frontNode->data;
    	            
    	        
    	        if(frontNode->left)
    	            q.push(frontNode->left);
    	            
    	        if(frontNode->right)
    	            q.push(frontNode->right);
    	    }
    	    LeftToRight = !LeftToRight;
    	    for(auto i : ans)
    	        answer.push_back(i);
    	}
    	return answer;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends