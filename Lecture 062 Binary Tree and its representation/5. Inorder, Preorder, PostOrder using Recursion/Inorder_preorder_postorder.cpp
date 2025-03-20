#include<iostream>
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

void Inorder(Node* root)
{
    //base case
    if(root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root)
{
    //base case
    if(root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root)
{
    //base case
    if(root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;
    cout << "Enter root data ";
    root = buildTree(root);

    cout << "Inorder : ";
    Inorder(root);
    cout << endl << "Preorder : "; 
    Preorder(root);
    cout << endl << "Postorder : ";
    Postorder(root);
}