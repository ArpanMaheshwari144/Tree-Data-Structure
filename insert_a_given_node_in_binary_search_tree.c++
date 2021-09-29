// Time Complexity -> O(log(n)) where n is number of nodes in the tree

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

struct Node *insertIntoBST(struct Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    struct Node *curr = root;
    while (true)
    {
        if (curr->data <= val)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

void inOrderRecursive(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(7);

    cout << "Before insertion in a binary search tree: ";
    inOrderRecursive(root);

    int nodeToBeInserted = 5;
    struct Node *ans = insertIntoBST(root, nodeToBeInserted);

    cout << "\nAfter insertion in a binary search tree: ";
    inOrderRecursive(ans);

    return 0;
}