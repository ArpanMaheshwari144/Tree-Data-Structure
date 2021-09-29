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

int widthOfBinaryTree(struct Node *root)
{
    if (!root)
    {
        return 0;
    }

    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int min_index = q.front().second; // to make the index starting from zero
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr_id = q.front().second - min_index;
            struct Node *node = q.front().first;
            q.pop();

            // store the first element
            if (i == 0)
            {
                first = curr_id;
            }

            // store the second element
            if (i == size - 1)
            {
                last = curr_id;
            }
            if (node->left)
            {
                q.push({node->left, curr_id * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, curr_id * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->right = new Node(2);

    cout << widthOfBinaryTree(root);

    return 0;
}