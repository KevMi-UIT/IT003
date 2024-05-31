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

bool ifInTree(Node *tree, int n)
{
    if (!tree)
        return false;
    if (tree->value == n)
        return true;
    // return ifInTree(tree->left, n) ? true : ifInTree(tree->right, n);
    return ifInTree(tree->left, n) || ifInTree(tree->right, n);
}

Node *findSameParrent(Node *tree, const int &a, const int &b)
{
    if (!tree)
        return tree;
    if (!(a <= tree->value && tree->value <= b))
        return NULL;
    Node *leftPar = findSameParrent(tree->left, a, b);
    Node *rightPar = findSameParrent(tree->right, a, b);
    if (leftPar)
        return leftPar;
    if (rightPar)
        return rightPar;
    return tree;
}

int distanceBetweenParAndNode(Node *par, int child)
{
    if (!par)
        return 1;
    if (par->value == child)
        return 0;
    int distanceFromLeft = 1 + distanceBetweenParAndNode(par->left, child);
    int distanceFromRight = 1 + distanceBetweenParAndNode(par->right, child);
    return distanceFromLeft < distanceFromRight ? distanceFromLeft : distanceFromRight;
}

int distanceBetweenNodes(Node *tree, int a, int b)
{
    if (!ifInTree(tree, a) || !ifInTree(tree, b))
        return -1;
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    Node *parrent = findSameParrent(tree, a, b);
    if (!parrent)
        return -1;
    return distanceBetweenParAndNode(parrent, a) + distanceBetweenParAndNode(parrent, b);
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
