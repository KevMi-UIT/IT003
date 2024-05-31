#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

Node *newNode(int v)
{
    Node *newNode = new Node;
    newNode->value = v;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node *root, Node *newNode)
{
    if (!root)
        return;

    if (newNode->value < root->value)
    {
        if (!root->left)
        {
            root->left = newNode;
            return;
        }
        insertNode(root->left, newNode);
        return;
    }

    if (!root->right)
    {
        root->right = newNode;
        return;
    }
    insertNode(root->right, newNode);
}

// Assuming you have a function to find the Lowest Common Ancestor (LCA)
Node *findLCA(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;
    if (root->value == a || root->value == b)
        return root;
    Node *left = findLCA(root->left, a, b);
    Node *right = findLCA(root->right, a, b);
    if (left != NULL && right != NULL)
        return root;                      // If a and b are on both sides
    return (left != NULL) ? left : right; // Either one of a,b is on one side OR a,b is not in L&R subtrees
}

// Function to find the distance from the root to a given node
int findDistance(Node *root, int value, int distance)
{
    if (root == NULL)
        return -1;
    if (root->value == value)
        return distance;
    int left = findDistance(root->left, value, distance + 1);
    if (left != -1)
        return left;
    return findDistance(root->right, value, distance + 1);
}

// Function to find the distance between two nodes in a BST
int distanceBetweenNodes(Node *root, int a, int b)
{
    Node *lca = findLCA(root, a, b);
    if (lca == NULL)
        return -1; // If LCA doesn't exist, return -1
    int distanceA = findDistance(lca, a, 0);
    int distanceB = findDistance(lca, b, 0);
    // Hey this below step isn't necessary!!!
    if (distanceA == -1 || distanceB == -1)
        return -1; // If either a or b doesn't exist, return -1
    return distanceA + distanceB;
}

int main()
{
    Node *tree = NULL;

    int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (!tree)
        {
            tree = newNode(val);
            continue;
        }

        insertNode(tree, newNode(val));
    }

    int a, b;
    cin >> a >> b;

    cout << distanceBetweenNodes(tree, a, b) << endl;

    return 0;
}
