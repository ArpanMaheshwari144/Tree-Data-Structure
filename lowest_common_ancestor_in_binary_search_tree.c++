// Time Complexity -> O(H) where H is the height of the binary serach tree

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
    if (root == NULL)
    {
        return NULL;
    }

    int curr = root->data;

    if (curr < p->data && curr < q->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (curr > p->data && curr > q->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(4);
    root->left->left = new Node(3);
    root->left->left->left = new Node(1);
    root->left->left->left->right = new Node(2);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->left->right->left->left = new Node(5);
    root->left->right->left->right = new Node(7);
    root->left->right->right = new Node(9);
    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(15);

    struct Node *first = root->left->left->left;
    struct Node *second = root->left->left->left->right;

    cout << lowestCommonAncestor(root, first, second)->data;

    return 0;
}