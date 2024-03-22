#include <iostream>
using namespace std;

void printArray(int arr[], int &n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            printArray(arr, n);
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionSort(a, n);

    return 0;
}
