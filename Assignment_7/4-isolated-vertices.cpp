#include <iostream>
#include <vector>
using namespace std;

bool checkExist(int a, const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        if (a == arr[i])
            return true;
    return false;
}
/* tét
6 5
0 1
0 3
1 3
2 3
4 5
:0
*/
int main()
{
    int v, e;
    vector<int> arr;
    cin >> v >> e;
    for (int i = 0; i < 2 * e; i++)
    {
        int a;
        cin >> a;
        if (!checkExist(a, arr))
            arr.push_back(a);
    }
    cout << v - arr.size() << endl;
    return 0;
}