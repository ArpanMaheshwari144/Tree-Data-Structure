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

vector<vector<int>> zigZagLevelOrderTraversal(struct Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            struct Node *node = q.front();
            q.pop();

            // find position to fill node's value
            // depending on the leftToRight flag value we insert the value from the front or backwards
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        // after completing one level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(6);

    vector<vector<int>> ans = zigZagLevelOrderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}