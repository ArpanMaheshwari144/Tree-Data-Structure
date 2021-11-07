// Time Complexity -> O(n)

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

class NodeValue
{
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeValue largestBSTSubtreeHelper(struct Node *root)
{
    // an empty tree is a BST of size 0
    if (!root)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // get values from left and right subtree of current tree
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // current node is greater than max in left and smaller than min in right, it is a BST
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        // it is a BST
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    // otherwise return [INT_MIN, INT_MAX] so that parent cannot be valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(struct Node *root)
{
    return largestBSTSubtreeHelper(root).maxSize;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum size of largest BST is: " << largestBSTSubtree(root);

    return 0;
}