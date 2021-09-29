// Amotised Time Complexity -> O(n) where n is number of nodes in the tree

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

vector<int> preOrderTraversal(struct Node *root)
{
    vector<int> preorder;
    struct Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            struct Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right = new Node(3);

    vector<int> preOrder = preOrderTraversal(root);
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }

    return 0;
}