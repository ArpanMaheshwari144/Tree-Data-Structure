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

bool getPath(struct Node *root, vector<int> &arr, int x)
{
    if (!root)
    {
        return false;
    }

    arr.push_back(root->data);

    if (root->data == x)
    {
        return true;
    }

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> solve(struct Node *root, int value)
{
    vector<int> arr;
    if (root == NULL)
    {
        return arr;
    }
    getPath(root, arr, value);
    return arr;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans = solve(root, 5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}