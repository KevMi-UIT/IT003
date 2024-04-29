
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
    bool checkBST(Node *root)
    {
        return checkBSTUtil(root, LONG_MIN, LONG_MAX);
    }

  private:
    bool checkBSTUtil(Node *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return true;

        if (root->data < minVal || root->data > maxVal)
            return false;

        return checkBSTUtil(root->left, minVal, root->data - 1) && checkBSTUtil(root->right, root->data + 1, maxVal);
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

    std::cout << myTree.checkBST(root);

    return 0;
}