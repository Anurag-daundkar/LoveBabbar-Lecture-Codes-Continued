#include<iostream>
#include<queue>
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

void LevelOrderTraversalPrinting(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp != NULL)
        {
            cout << temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        else
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

    }
}

int main()
{
    Node* root = NULL;
    cout << "Enter data for root Node ";
    root = buildTree(root);

    LevelOrderTraversalPrinting(root);
}