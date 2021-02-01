#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node *bstInsert(Node *root, int data)
{
    if (root)
    {
        if (root->data < data)
        {
            root->right = bstInsert(root->right, data);
        }
        else if (root->data > data)
        {
            root->left = bstInsert(root->left, data);
        }
        return root;
    }
    Node *temp = new Node(data);
    return temp;
}
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/*
      10
    /   \
   6    13
 / \
4  8
*/
int main()
{
    Node *root = nullptr;
    root = bstInsert(root, 10);
    root = bstInsert(root, 6);
    root = bstInsert(root, 4);
    root = bstInsert(root, 8);
    root = bstInsert(root, 8);
    root = bstInsert(root, 13);
    inorder(root);
    cout << endl;
    return 0;
}