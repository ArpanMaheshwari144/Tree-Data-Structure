// Time Complexity -> O(n) where n is number of elements in the vector

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

struct Node *build(vector<int> &preOrder, int &i, int upperBound)
{
    if (i == preOrder.size() || preOrder[i] > upperBound)
    {
        return NULL;
    }

    struct Node *root = new Node(preOrder[i++]);
    root->left = build(preOrder, i, root->data);
    root->right = build(preOrder, i, upperBound);
    return root;
}

struct Node *bstFromPreOrder(vector<int> &preOrder)
{
    int i = 0; // pointer
    return build(preOrder, i, INT_MAX);
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
    vector<int> preOrder = {8, 5, 1, 7, 10, 12};

    struct Node *ans = bstFromPreOrder(preOrder);
    cout << "Root of the tree is: " << ans->data << endl;

    cout << "Inorder of the tree is: ";
    inOrderRecursive(ans);

    return 0;
}