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

//-------------------------------one way -----------------------------------
Node* BuildTree(Node* root)
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
        root->left = BuildTree(root->left);

        cout << "Enter data for right of " << data << " ";
        root->right = BuildTree(root->right);
    }
}

//-----------------------------------another way ----------------------------
// void BuildTree(Node*& root)
// {
//     int data;
//     cin >> data;

//     if(data == -1)
//     {
//         return ;
//     }

//     else
//     {
//         root = new Node(data);

//         cout << "Enter data for left of " << data << " ";
//         BuildTree(root->left);
        
//         cout<<"Enter data for right of " << data << " ";
//         BuildTree(root->right);
//     }
// }

int main()
{
    Node* root = NULL;
    cout << "Enter root data ";
    BuildTree(root);
}