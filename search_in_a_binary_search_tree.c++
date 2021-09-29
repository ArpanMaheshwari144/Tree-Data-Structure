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

struct Node *searchBST(struct Node *root, int val)
{
    while (root != NULL && root->data != val)
    {
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

int main()
{
    struct Node *root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right = new Node(12);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    struct Node *ans = searchBST(root, 10);
    if (ans != NULL)
    {
        cout << "Present" << endl;
        cout << ans->data;
    }
    else
    {
        cout << "Not Present";
    }

    return 0;
}