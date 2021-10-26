// Given a Binary Tree and return whether that tree is Binary Search Tree or not

// TC -> O(n) and SC -> O(1)

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

bool isValidBST(struct Node *root, int minValue, int maxValue)
{
    if (root == NULL)
    {
        return true;
    }

    // checking the node is in between the range or not
    if (root->data >= maxValue || root->data <= minValue)
    {
        return false;
    }

    return isValidBST(root->left, minValue, root->data) && isValidBST(root->right, root->data, maxValue);
}

bool checkBST(struct Node *root)
{
    return isValidBST(root, INT_MIN, INT_MAX);
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(8);

    // struct Node *root = new Node(2);
    // root->left = new Node(1);
    // root->right = new Node(3);

    bool ans = checkBST(root);
    if (ans)
    {
        cout << "Yes, it is a BST";
    }
    else
    {
        cout << "Not, it is not a BST";
    }

    return 0;
}