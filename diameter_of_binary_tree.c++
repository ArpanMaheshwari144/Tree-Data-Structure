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

int heightOfBinaryTree(struct Node *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(root->left, diameter);
    int rightHeight = heightOfBinaryTree(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(struct Node *root)
{
    int diameter = 0;
    heightOfBinaryTree(root, diameter);
    return diameter;
}

int main()
{
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->right->left = new Node(4);
    // root->right->left->left = new Node(5);
    // root->right->left->left->left = new Node(9);
    // root->right->right = new Node(6);
    // root->right->right->right = new Node(7);
    // root->right->right->right->right = new Node(8);

    struct Node *root = new Node(1);
    root->left = new Node(2);

    int ans = diameterOfBinaryTree(root);
    cout << "The diameter of a binary tree is: " << ans << endl;

    return 0;
}