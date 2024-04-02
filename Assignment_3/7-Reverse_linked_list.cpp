
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode
{
  public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
  public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};
void print_singly_linked_list(SinglyLinkedListNode *node, char sep = ' ')
{
    while (node)
    {
        cout << node->data;

        node = node->next;

        if (node)
        {
            cout << sep;
        }
    }
    cout << '\n';
}

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void print_singly_linked_list(SinglyLinkedListNode *node, char sep = ' ')
{
    while (node)
    {
        cout << node->data;

        node = node->next;

        if (node)
        {
            cout << sep;
        }
    }
    cout << '\n';
}
void insert_node(SinglyLinkedList *List, int x)
{
    SinglyLinkedListNode *node = new SinglyLinkedListNode(x);

    if (!List->head)
    {
        List->head = node;
    }
    else
    {
        List->tail->next = node;
    }

    List->tail = node;
}

void reverseLinkedList(SinglyLinkedList List)
{
    SinglyLinkedList *temp = new SinglyLinkedList;
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();
    int llist_count;

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }

    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
