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

bool isSymmetricHelp(struct Node *left, struct Node *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }

    if (left->data != right->data)
    {
        return false;
    }

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(struct Node *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool ans = isSymmetric(root);
    if (ans)
    {
        cout << "Symmetric";
    }
    else
    {
        cout << "Not Symmetric";
    }

    return 0;
}