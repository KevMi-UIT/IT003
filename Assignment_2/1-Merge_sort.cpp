#include <iostream>
using namespace std;

void PrintOut(const int arr[], const int &l, const int &r, const int &n)
{
    for (int i = 0; i < l; i++)
        cout << arr[i] << " ";
    cout << "[ ";
    for (int i = l; i <= r; i++)
        cout << arr[i] << " ";
    cout << "] ";
    for (int i = r + 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
            arr[k++] = L[i++];
        else
            arr[k++] = M[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = M[j++];
}

void mergeSort(int arr[], int l, int r, const int &n)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        merge(arr, l, m, r);
        PrintOut(arr, l, r, n);
    }
}

int main()
{
    int n;
    cin >> n;
    // int *a = new int[n];
    int a[500];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1, n - 1);
    // delete[] a;
    return 0;
}
