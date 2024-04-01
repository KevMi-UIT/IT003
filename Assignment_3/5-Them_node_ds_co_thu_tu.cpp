/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void free_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
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
SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x)
{

    int count = 0;
    int pos = 0;
    SinglyLinkedListNode* node = new SinglyLinkedListNode(x);
    SinglyLinkedListNode* p2 = head;
    SinglyLinkedListNode* p1 = p2;
    if (p2 == NULL)
        return node;

    while (p1->next != NULL)
    {
        count++;
        p1 = p1->next;
    }
    while (p2->data < x && p2->next != NULL)
    {
        pos++;
        p2 = p2->next;
    }
    if (p2->data < x)
        pos++;
    if (pos == 0)
    {
        node->next = head;
        head = node;
    }

    else if (pos > count)
    {
        p2->next = node;
    }

    else
    {
        SinglyLinkedListNode* temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
    return head;
}
int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    cin >> x;
    llist->head = insertSortedLinkedList(llist->head, x);
    printLinkedList(llist->head);

    return 0;
}
