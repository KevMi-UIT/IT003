
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
        static Node *prev = NULL;
        if (root == NULL)
            return true;

        if (!checkBST(root->left))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;
        return checkBST(root->right);
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