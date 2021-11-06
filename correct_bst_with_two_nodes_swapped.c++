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

class Solution
{
public:
    struct Node *first;
    struct Node *prev;
    struct Node *middle;
    struct Node *last;

    void inOrder(struct Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void inOrderRecoverTree(struct Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inOrderRecoverTree(root->left);

        if (prev != NULL && (root->data < prev->data))
        {
            // if this is first violation, mark these two nodes as 'first' and 'middle'
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }

            // if this is second violation, mark this node as last
            else
            {
                last = root;
            }
        }

        // mark this node as previous
        prev = root;
        inOrderRecoverTree(root->right);
    }

    void recoverTree(struct Node *root)
    {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);

        inOrderRecoverTree(root);

        if (first && last)
        {
            swap(first->data, last->data);
        }
        else if (first && middle)
        {
            swap(first->data, middle->data);
        }
    }
};

int main()
{
    struct Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    Solution obj;

    cout << "Before correct the BST: ";
    obj.inOrder(root);

    obj.recoverTree(root);

    cout << "\nAfter correct the BST: ";
    obj.inOrder(root);

    return 0;
}