// Time Complexity -> O(H) where H is the height of the binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

struct Node *inorderSuccessor(struct Node *root, struct Node *val)
{
    struct Node *successor = NULL;

    while (root != NULL)
    {
        if (val->data >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    struct Node *val = root->right->right->left;

    struct Node *ans = inorderSuccessor(root, val);

    if (ans)
    {
        cout << "Successor of " << val->data << " is: " << ans->data;
    }
    else
    {
        cout << "Successor of " << val->data << " is: " << -1;
    }
    return 0;
}