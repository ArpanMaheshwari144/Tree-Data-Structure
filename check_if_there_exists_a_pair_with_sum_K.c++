// Time Complexity -> O(n) where n is the number of nodes and Space Complexity -> O(H) * 2

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

class BSTIterator
{
    stack<Node *> s;

    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;

public:
    BSTIterator(struct Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    // return whether we have a next smallest number
    bool hasNext()
    {
        /* bcoz s.empty() returns true when stack is empty so we want to convert that value into false */
        return !s.empty();
    }

    // return the next smallest number
    int next()
    {
        struct Node *tempNode = s.top();
        s.pop();

        if (!reverse)
        {
            pushAll(tempNode->right);
        }
        else
        {
            pushAll(tempNode->left);
        }
        return tempNode->data;
    }

    void pushAll(struct Node *node)
    {
        for (; node != NULL;) // while (root != NULL){}
        {
            s.push(node);

            // for before element -> push all right element
            if (reverse == true)
            {
                node = node->right;
            }

            // for next element -> push all left element
            else
            {
                node = node->left;
            }
        }
    }
};

class Solution
{
public:
    bool findTarget(struct Node *root, int k)
    {
        if (!root)
        {
            return NULL;
        }

        BSTIterator l(root, false); // left means for next element
        BSTIterator r(root, true);  // right means for before element

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
            {
                cout << "Elements are: " << i << " " << j;
                return true;
            }
            else if (i + j < k)
            {
                i = l.next();
            }
            else
            {
                j = r.next();
            }
        }
        return false;
    }
};

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(7);

    int k = 9;

    Solution obj;
    if (obj.findTarget(root, k))
    {
        cout << "\nElements are found";
    }
    else
    {
        cout << "\nElements are not found";
    }

    return 0;
}