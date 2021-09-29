/* Note :
1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
2. You can not change the structure of the original binary tree.
3. A binary tree is a tree in which each node has at most two children.      
4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.
*/

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

void changeBinaryTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
            root->right->data = root->data;
        }
    }

    changeBinaryTree(root->left);
    changeBinaryTree(root->right);

    int total = 0;
    if (root->left)
    {
        total += root->left->data;
    }
    if (root->right)
    {
        total += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = total;
    }
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
    struct Node *root = new Node(40);
    root->left = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    cout << "Before children sum property: ";
    inOrderRecursive(root);

    changeBinaryTree(root);

    cout << "\nAfter children sum property: ";
    inOrderRecursive(root);

    return 0;
}