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

struct Node *lowestCommonAncestor(struct Node *root, struct Node *p, struct Node *q)
{
    // base case
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    struct Node *left = lowestCommonAncestor(root->left, p, q);
    struct Node *right = lowestCommonAncestor(root->right, p, q);

    // result
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        // both the left and right are not null, we found are result
        return root;
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(8);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    struct Node *first = root->right->left->left;
    struct Node *second = root->right->right->right;

    cout << lowestCommonAncestor(root, first, second)->data;

    return 0;
}