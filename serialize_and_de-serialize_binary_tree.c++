// Time Complexity -> O(n) where n is number of nodes in the tree

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
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

class Codec
{
public:
    // Encode a tree to a single string
    string serialize(struct Node *root)
    {
        if (!root)
        {
            return "";
        }

        string s = "";
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            struct Node *currNode = q.front();
            q.pop();

            if (currNode == NULL)
            {
                // # represents null in the tree
                s.append("#,");
            }
            else
            {
                s.append(to_string(currNode->data) + ',');
            }

            if (currNode != NULL)
            {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    struct Node *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }

        /* A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). */
        stringstream s(data);
        string str;

        /* (stringstream, string, delimeter)
        1. stringstream -> It is an object of istream class and tells the function about the stream from where to read the input from.
        2. string ->  It is a string object, the input is stored in this object after being read from the stream.
        3. delimeter -> It is the delimitation character which tells the function to stop reading further input after reaching this character.
        */
        getline(s, str, ',');
        struct Node *root = new Node(stoi(str));
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            struct Node *node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                struct Node *leftNode = new Node(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                struct Node *rightNode = new Node(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

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
    Codec obj;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string ans = obj.serialize(root);
    cout << ans << endl;

    struct Node *newNode = obj.deserialize(ans);
    inOrderRecursive(newNode);

    return 0;
}