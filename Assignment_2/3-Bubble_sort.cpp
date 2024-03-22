#include <iostream>
using namespace std;
#define MAXN 1000

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void printArray(long a[MAXN], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleSort(long arr[MAXN], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                printArray(arr, n);
            }
        }
    }
}

void inputArr(long a[MAXN], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    long a[MAXN];
    int n;
    inputArr(a, n);
    bubbleSort(a, n);
    return 0;
}
