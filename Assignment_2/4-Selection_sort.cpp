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

void selectionSort(long arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            swap(arr[min_idx], arr[i]);
            printArray(arr, n);
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
    selectionSort(a, n);
    return 0;
}
