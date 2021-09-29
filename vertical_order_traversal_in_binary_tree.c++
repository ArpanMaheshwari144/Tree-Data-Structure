// Time Complexity -> O(n)log(n) where n is number of nodes in the tree

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

vector<vector<int>> verticalTraversal(struct Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo; // (node, {vertical, level})
    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        struct Node *node = p.first;                 // node
        int x = p.second.first, y = p.second.second; // vertical and level
        nodes[x][y].insert(node->data);
        if (node->left)
        {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    vector<vector<int>> ans = verticalTraversal(root);
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