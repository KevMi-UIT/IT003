#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (ceil(sqrt(n)) == sqrt(n))
        cout << 1;
    else
        cout << 0;
    return 0;
}
