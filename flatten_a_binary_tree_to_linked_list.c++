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

// Approach 1 -> TC - O(N)
void flattenTree1(struct Node *root)
{
    while (root)
    {
        if (root->left && root->right)
        {
            // finding rightmost in the left subtree
            struct Node *t = root->left;
            while (t->right)
            {
                t = t->right;
            }
            /* right subtree of the current node will become right child of the rightmost child in the left         subtree */
            t->right = root->right;
        }
        if (root->left)
        {
            // assign right subtree with left subtree
            root->right = root->left;
        }
        root->left = NULL;
        root = root->right;
    }
}

// Approach 2 -> TC - O(N)
void flattenTree2(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        struct Node *curr = st.top();
        st.pop();

        if (curr->right != NULL)
        {
            st.push(curr->right);
        }
        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
        if (!st.empty())
        {
            curr->right = st.top();
        }
        curr->left = NULL;
    }
}

// Approach 3 -> TC - O(N)
void flattenTree3(struct Node *root)
{
    struct Node *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            struct Node *pre = curr->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
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
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // flattenTree1(root);
    // flattenTree2(root);
    flattenTree3(root);
    inOrderRecursive(root);

    return 0;
}