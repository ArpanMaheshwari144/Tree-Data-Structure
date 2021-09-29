// Time Complexity -> O(2n) where n is number of nodes in the tree

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

vector<int> postOrderIterative(struct Node *root)
{
    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }

    stack<Node *> st;
    struct Node *current = root;
    while (current != NULL || !st.empty())
    {
        if (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            struct Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                current = temp;
            }
        }
    }
    return postorder;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->right = new Node(5);
    root->left->left->right->right->right = new Node(6);
    root->right = new Node(7);
    root->right->left = new Node(8);

    vector<int> vect = postOrderIterative(root);
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }

    return 0;
}