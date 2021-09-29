// Time Complexity -> O(log(n)^2) where n is number of nodes in the tree

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

int findHeightLeft(struct Node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}

int findHeightRight(struct Node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = findHeightLeft(root);
    int rightHeight = findHeightRight(root);

    if (leftHeight == rightHeight)
    {
        // return 2^leftHeight - 1
        return (1 << leftHeight) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << countNodes(root);

    return 0;
}