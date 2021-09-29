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

bool isSameTree(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return (root1 == root2);
    }

    return (root1->data || root2->data) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

int main()
{
    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(5);

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);

    bool ans = isSameTree(root1, root2);
    if (ans)
    {
        cout << "Same trees";
    }
    else
    {
        cout << "Different trees";
    }

    return 0;
}