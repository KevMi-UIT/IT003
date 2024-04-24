
#include <bits/stdc++.h>
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
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    void postOrder(Node *root)
    {
        stack<Node *> nodeStack;
        stack<Node *> nodeStackSecond;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            Node *cur = nodeStack.top();
            nodeStack.pop();
            nodeStackSecond.push(cur);
            if (cur->left)
                nodeStack.push(cur->left);
            if (cur->right)
                nodeStack.push(cur->right);
        }
        while (!nodeStackSecond.empty())
        {
            cout << nodeStackSecond.top()->data << " ";
            nodeStackSecond.pop();
        }
    }

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.postOrder(root);

    return 0;
}
