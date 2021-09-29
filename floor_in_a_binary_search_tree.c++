// Time Complexity -> O(log(n)) where n is number of nodes in the tree

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

int floorBST(struct Node *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }

        if (key > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right = new Node(15);

    int ans = floorBST(root, 14);
    if (ans)
    {
        cout << ans;
    }
    else
    {
        cout << "Not Present";
    }

    return 0;
}