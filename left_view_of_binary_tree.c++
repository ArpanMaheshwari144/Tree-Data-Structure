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

void recursion(struct Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }

    // first time I came across to this level
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
}

vector<int> leftView(struct Node *root)
{
    vector<int> res;
    recursion(root, 0, res);
    return res;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = leftView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}