#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root)
{
    int data;
    cin >> data;

    if(data == -1)
    {
        return NULL;
    }

    else
    {
        root = new Node(data);

        cout << "Enter data for left of " << data << " ";
        root->left = buildTree(root->left);
        
        cout << "Enter data for right of " << data << " ";
        root->right = buildTree(root->right);   
    }
}

void ReverseLevelOrderTraversalPrinting(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    stack<Node*> s;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        if(temp != NULL)
        {
            s.push(temp);

            if(temp->right)
            q.push(temp->right);

            if(temp->left)
                q.push(temp->left);
        }
    }

    while(!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    Node* root = NULL;
    cout << "Enter data for root Node ";
    root = buildTree(root);

    ReverseLevelOrderTraversalPrinting(root);
}