#include <iostream>

using namespace std;

class Good
{
  public:
    int name;
    int sell;
    Good(int name = 0, int sell = 0)
    {
        name = name;
        sell = sell;
    }
};

struct Node
{
    Good good;
    Node *next;
};

int main()
{
    int numberOfBill = 0;
    cin >> numberOfBill;
    int goodInput;
    cin >> goodInput;
    Node list{goodInput, NULL};
    Node headNode;
    bool check = false;
    for (int i = 1; i < numberOfBill; ++i)
    {
        check = false;
        headNode = list;
        cin >> goodInput;
        while (list.next != NULL)
        {
            if (goodInput < list.good.name)
            {
                list = {goodInput, &list};
                check = true;
                break;
            }
            if (goodInput == list.good.name)
            {
                ++list.good.sell;
                list = headNode;
                check = true;
                break;
            }
            list = *list.next;
        }
        if (!check)
        {
            Node newNode = {goodInput, NULL};
            list.next = &newNode;
            list = headNode;
        }
    }
    headNode = list;
    Node secondList = {list.good, NULL};
    Node headSecondList = secondList;
    list = *list.next;
    while (list.next != NULL)
    {
        headSecondList = secondList;
        while (secondList.next != NULL)
        {
            if (list.good.sell > secondList.good.sell)
            {
                Node newNode = {list.good, &secondList};
                secondList = newNode;
                check = true;
                break;
            }
            if (list.good.sell == secondList.good.sell)
            {
                if (list.good.name < secondList.good.name)
                {
                }
            }
        }
    }
    return 0;
}
