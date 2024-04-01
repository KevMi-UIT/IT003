#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }
};

struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void Nhap(DATHUC &B, const double &heso, const int &somu)
{
    DONTHUC *donThuc = new DONTHUC(heso, somu);
    Node *node = new Node(donThuc);
    if (!B.head)
    {
        B.head = B.tail = node;
        return;
    }
    B.tail->next = node;
    B.tail = node;
}

void Xuat(DATHUC &daThuc)
{
    Node *temp = daThuc.head;
    bool isFirst = true;
    bool hasNonZeroTerm = false;
    while (temp != nullptr)
    {
        if (temp->data->heso != 0)
        {
            hasNonZeroTerm = true;
            if (!isFirst && temp->data->heso > 0)
                cout << "+";
            if (abs(temp->data->heso) != 1 || temp->data->somu == 0)
                cout << temp->data->heso;
            if (temp->data->somu != 0)
            {
                cout << "x";
                if (temp->data->somu != 1)
                {
                    cout << "^" << temp->data->somu;
                }
            }
            isFirst = false;
        }
        temp = temp->next;
    }
    if (!hasNonZeroTerm)
        cout << "0";
    cout << endl;
}

double TinhDaThuc(const DATHUC &B, const double &x)
{
    double res = 0;
    Node *tempHead = B.head;
    while (tempHead)
    {
        res += tempHead->data->heso * pow(x, tempHead->data->somu);
        tempHead = tempHead->next;
    }
    return res;
}

int main()
{
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: " << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
