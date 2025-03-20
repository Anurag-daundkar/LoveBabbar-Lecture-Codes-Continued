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

Node* buildTreefromLevelOrder(Node* root)
{
    queue<Node*> q;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftdata;
        cout << "Enter left of " << temp->data << " ";
        cin >> leftdata;

        if(leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout << "Enter right of " << temp->data << " ";
        cin >> rightdata;

        if(rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
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
    root = buildTreefromLevelOrder(root);

    cout << "Inorder : ";
    Inorder(root);
    cout << endl << "Preorder : "; 
    Preorder(root);
    cout << endl << "Postorder : ";
    Postorder(root);
}