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

void getPath(struct Node *root, vector<int> arr, vector<vector<int>> &ans)
{
    if (!root)
    {
        return;
    }

    arr.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(arr);
    }
    getPath(root->left, arr, ans);
    getPath(root->right, arr, ans);
}

vector<vector<int>> solve(struct Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> arr;
    getPath(root, arr, ans);
    return ans;
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

    vector<vector<int>> ans = solve(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}