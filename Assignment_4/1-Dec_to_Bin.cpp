#include <iostream>
#include <stack>
using namespace std;

void convertDectoBin(int x)
{
    stack<int> BIT;
    int odd;
    while (x)
    {
        odd = x % 2;
        BIT.push(odd);
        x /= 2;
    }
    int size = BIT.size();
    for (int i = 0; i < size; i++)
    {
        cout << BIT.top();
        BIT.pop();
    }
}
int main()
{
    int dec;
    cin >> dec;
    convertDectoBin(dec);
    return 0;
}