// Time Complexity -> O(1) and Space Complexity -> O(H) where H is the height of the tree

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

public:
    BSTIterator(struct Node *root)
    {
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
        pushAll(tempNode->right);
        return tempNode->data;
    }

    // this will push all the left elements into the stack
    void pushAll(struct Node *root)
    {
        for (; root != NULL; s.push(root), root = root->left)
            ;
    }
};

int main()
{
    struct Node *root = new Node(7);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->left->left = new Node(4);
    root->right = new Node(10);
    root->right->left = new Node(9);
    root->right->left->left = new Node(8);

    BSTIterator obj(root);

    cout << "Next element: " << obj.next() << endl;
    cout << "Next element: " << obj.next() << endl;
    cout << "Next element: " << obj.next() << endl;

    cout << "Has next element: ";
    if (obj.hasNext())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << "Next element: " << obj.next() << endl;
    cout << "Next element: " << obj.next() << endl;

    cout << "Has next element: ";
    if (obj.hasNext())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << "Next element: " << obj.next() << endl;
    cout << "Next element: " << obj.next() << endl;
    cout << "Next element: " << obj.next() << endl;

    cout << "Has next element: ";
    if (obj.hasNext())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << "Next element: " << obj.next() << endl;
    cout << "Next element: " << obj.next() << endl;

    cout << "Has next element: ";
    if (obj.hasNext())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}