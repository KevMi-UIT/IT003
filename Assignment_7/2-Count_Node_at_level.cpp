
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
    int levelOrder(Node *root, int targetLevel)
    {
        int level = 0;
        queue<Node *> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            int nodeCount = nodeStack.size();
            if (level == targetLevel)
                return nodeCount;
            while (nodeCount > 0)
            {
                Node *cur = nodeStack.front();
                nodeStack.pop();
                if (cur->left)
                    nodeStack.push(cur->left);
                if (cur->right)
                    nodeStack.push(cur->right);
                nodeCount--;
            }
            level++;
        }
        return 0;
    }
}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;
    int targetLevel;
    int t;
    int data;

    std::cin >> t;
    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    cin >> targetLevel;
    cout << myTree.levelOrder(root, targetLevel);

    return 0;
}
