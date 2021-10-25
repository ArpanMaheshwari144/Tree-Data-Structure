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

// Morris traversal -> TC -> O(n)
int kthLargest(struct Node *root, int k)
{
    stack<Node *> st;
    struct Node *node = root;
    int count = 0;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->right;
        }
        else
        {
            if (st.empty())
            {
                break;
            }

            node = st.top();
            st.pop();
            count++;
            if (count == k)
            {
                return node->data;
            }
            node = node->left;
        }
    }
    return -1;
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->left->right = new Node(2);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 4; // what is the kth smallest element in that tree

    int ans = kthLargest(root, k);

    if (ans == -1)
    {
        cout << "Cannot find the element";
    }
    else
    {
        cout << k << "th largest element is: " << ans;
    }

    return 0;
}