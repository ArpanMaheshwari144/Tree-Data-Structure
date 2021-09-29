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

void preOrderinOrderpostOrder(struct Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> preOrder, inOrder, postOrder;
    if (root == NULL)
    {
        return;
    }

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part of pre increment 1 to 2 push the left side of the tree
        if (it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in increment 2 to 3 push right
        else if (it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }

        // don't push it back again
        else
        {
            postOrder.push_back(it.first->data);
        }
    }

    cout << "Preorder: ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }

    cout << endl;

    cout << "Inorder: ";
    for (int i = 0; i < inOrder.size(); i++)
    {
        cout << inOrder[i] << " ";
    }

    cout << endl;

    cout << "Postorder: ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrderinOrderpostOrder(root);

    return 0;
}
