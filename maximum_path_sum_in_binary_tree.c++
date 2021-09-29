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

int maxPathDown(struct Node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    // if left gives negative, so we return 0
    int leftSum = max(0, maxPathDown(root->left, maxi));

    // if right gives negative, so we return 0
    int rightSum = max(0, maxPathDown(root->right, maxi));

    maxi = max(maxi, leftSum + rightSum + root->data);

    return max(leftSum, rightSum) + root->data;
}

int maxPathSum(struct Node *root)
{
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main()
{
    struct Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int ans = maxPathSum(root);
    cout << "Maximum sum is: " << ans;

    return 0;
}