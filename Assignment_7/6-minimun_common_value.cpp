#include <iostream>
#include <vector>
using namespace std;

int smallestCommon(vector<int> nums1, vector<int> nums2)
{
    int i = 0;
    int j = 0;
    int n = nums1.size();
    int m = nums2.size();
    int minVal1 = nums1[i];
    int minVal2 = nums2[j];
    while (i < n && j < m)
    {
        if (minVal1 == minVal2)
            return minVal1;
        else if (minVal1 < minVal2)
            minVal1 = nums1[i++];
        else if (minVal1 > minVal2)
            minVal2 = nums2[j++];
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums1;
    vector<int> nums2;

    int val = 0;
    for (auto i = 0; i < n; i++)
    {
        cin >> val;
        nums1.push_back(val);
    }
    for (auto i = 0; i < m; i++)
    {
        cin >> val;
        nums2.push_back(val);
    }

    cout << smallestCommon(nums1, nums2) << endl;

    return 0;
}
