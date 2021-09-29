// Time Complexity -> (O(n)+(log(n))) where n is number of nodes in the tree

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

Node *buildTreePostIn(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &mp)
{
    if (postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    Node *root = new Node(postorder[postEnd]);
    int inRoot = mp[postorder[postEnd]];

    Node *leftchild = buildTreePostIn(inorder, inStart, inRoot - 1, postorder, postStart, postStart + inRoot - inStart - 1, mp);
    Node *rightchild = buildTreePostIn(inorder, inRoot + 1, inEnd, postorder, postStart + inRoot - inStart, postEnd - 1, mp);

    root->left = leftchild;
    root->right = rightchild;

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
    {
        return NULL;
    }

    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
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
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    struct Node *node = buildTree(inorder, postorder);
    inOrderRecursive(node);

    return 0;
}