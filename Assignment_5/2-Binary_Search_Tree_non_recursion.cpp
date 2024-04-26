#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
  public:
    Node *insert(Node *root, int data)
    {
        Node *newNode = new Node(data);
        Node *parent = NULL;
        Node *current = root;

        while (current != NULL)
        {
            parent = current;
            if (data < current->data)
            {
                current = current->left;
            }
            else if (data > current->data)
            {
                current = current->right;
            }
        }

        if (parent == NULL)
        {
            parent = newNode;
        }
        else if (data < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }

        return root ? root : newNode;
    }
};

int main()
{
    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }

    return 0;
}
