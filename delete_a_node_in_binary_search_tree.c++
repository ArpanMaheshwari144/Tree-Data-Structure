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

struct Node *findLastRight(struct Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}

struct Node *helper(struct Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {
        return root->right;
    }

    struct Node *rightChild = root->right;
    struct Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return helper(root);
    }

    struct Node *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
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

    cout << "Before deletion in a binary search tree: ";
    inOrderRecursive(root);

    int nodeToBeDeleted = 1;
    struct Node *ans = deleteNode(root, nodeToBeDeleted);

    cout << "\nAfter deletion in a binary search tree: ";
    inOrderRecursive(ans);

    return 0;
}