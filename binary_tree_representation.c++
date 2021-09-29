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

void printTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<struct Node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        int nodeCount = q.size();

        while (nodeCount > 0)
        {
            struct Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            nodeCount--;
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    
    printTree(root);

    return 0;
}