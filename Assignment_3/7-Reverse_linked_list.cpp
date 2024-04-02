
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
void printLinkedList(SinglyLinkedList *list)
{
    SinglyLinkedListNode *p;
    p = list->head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
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

void reverseLinkedList(SinglyLinkedList *List)
{
    int count = 0;
    SinglyLinkedListNode *p1 = List->head;
    SinglyLinkedListNode *p2 = p1;
    SinglyLinkedListNode *p3 = p1;

    while (p1)
    {
        count++;
        p1 = p1->next;
    }

    int *tempList = new int[count];
    for (int i = 0; i < count; i++)
    {
        tempList[i] = p2->data;
        p2 = p2->next;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        p3->data = tempList[i];
        p3 = p3->next;
    }
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
