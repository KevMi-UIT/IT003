#define MAX 1000001
#include <iostream>

using namespace std;

struct Point
{
    long x;
    long y;
};
typedef Point POINT;

struct Flat
{
    Point *points = new Point[MAX];
    int size;
};
typedef Flat FLAT;

int SoSanh(const POINT &point_1, const POINT &point_2)
{
    if (point_1.x > point_2.x)
        return 1;
    if (point_1.x == point_2.x)
        if (point_2.y > point_1.y)
            return 1;
        else if (point_1.y == point_2.y)
            return 0;
    return -1;
}

int partition(POINT points[], const int &start, const int &end)
{
    POINT pivot = points[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
        if (SoSanh(points[i], pivot) <= 0)
            count++;
    int pivotIndex = start + count;
    swap(points[pivotIndex], points[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (SoSanh(points[i], pivot) <= 0)
            i++;
        while (SoSanh(points[j], pivot) > 0)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(points[i++], points[j--]);
    }
    return pivotIndex;
}

void XapXep(Point points[], const int &start, const int &end)
{
    if (start >= end)
        return;
    int pivot = partition(points, start, end);
    XapXep(points, start, pivot - 1);
    XapXep(points, pivot + 1, end);
}

int main()
{
    FLAT flat;
    cin >> flat.size;
    for (int i = 0; i < flat.size; ++i)
        cin >> flat.points[i].x >> flat.points[i].y;
    XapXep(flat.points, 0, flat.size - 1);
    for (int i = 0; i < flat.size; ++i)
        cout << flat.points[i].x << " " << flat.points[i].y << "\n\n";
    delete[] flat.points;
    return 0;
}
