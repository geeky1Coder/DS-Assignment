#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    /*flag for post order*/
    bool flag;
    Node(int x)
    {
        data = x;
        flag = 0;
        left = nullptr;
        right = nullptr;
    }
};
void iterativeInOrder(Node *root)
{
    Node *temp = root;
    std::stack<Node *> Stack;
    while (1)
    {
        if (temp == nullptr)
        {
            if (!Stack.empty())
            {
                Node *top = Stack.top();
                if (top->right)
                {
                    temp = top->right;
                }
                cout << top->data << " ";
                Stack.pop();
            }
            else
            {
                break;
            }
        }
        else
        {
            Stack.push(temp);
            temp = temp->left;
        }
    }
}
void iterativePostOrder(Node *root)
{
    Node *temp = root;
    std::stack<Node *> Stack;

    while (1)
    {
        if (temp == nullptr)
        {
            if (!Stack.empty())
            {
                while (!Stack.empty() && Stack.top()->flag == true)
                {
                    Node *x = Stack.top();
                    cout << x->data << " ";
                    Stack.pop();
                }
                if (!Stack.empty() && Stack.top()->flag == false)
                {
                    temp = Stack.top();
                    temp->flag = true;
                    Stack.pop();
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            temp->flag = true;
            Stack.push(temp);
            if (temp->right)
            {
                temp->right->flag = false;
                Stack.push(temp->right);
            }
            temp = temp->left;
        }
    }
}
void iterativePreOrder(Node *root)
{
    std::stack<Node *> Stack;
    Node *temp = root;
    while (1)
    {
        if (temp == nullptr)
        {
            if (!Stack.empty())
            {
                temp = Stack.top();
                Stack.pop();
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->right)
            {
                Stack.push(temp->right);
            }
            temp = temp->left;
        }
    }
}
/*
      10
    /   \
   18    13
 / \    /
4  8   32
*/
int main()
{
    Node *root = new Node(10);
    root->left = new Node(18);
    root->right = new Node(13);
    root->right->left = new Node(32);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    cout << "Iterative Preorder: ";
    iterativePreOrder(root);
    cout << endl;
    cout << "Iterative Inorder: ";
    iterativeInOrder(root);
    cout << endl;
    cout << "Iterative Postorder: ";
    iterativePostOrder(root);
    cout << endl;
    return 0;
}
