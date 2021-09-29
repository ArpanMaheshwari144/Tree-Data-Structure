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

int maxDepth(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int heightOfLeftSubTree = maxDepth(root->left);
    int heightOfRightSubTree = maxDepth(root->right);

    return 1 + max(heightOfLeftSubTree, heightOfRightSubTree);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);

    int ans = maxDepth(root);
    cout << ans;

    return 0;
}