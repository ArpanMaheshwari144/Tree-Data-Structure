// Time Complexity -> O(n) where n is number of nodes in the tree

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

int checkBalanceBinaryTree(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = checkBalanceBinaryTree(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }
    int rightHeight = checkBalanceBinaryTree(root->right);
    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(9);
    root->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    root->right->right->right->right = new Node(8);

    int ans = checkBalanceBinaryTree(root);
    if (ans <= -1)
    {
        cout << "Not a balanced binary tree" << endl;
    }
    else
    {
        cout << "Balanced binary tree" << endl;
        cout << "Height of the binary tree is: " << ans;
    }

    return 0;
}