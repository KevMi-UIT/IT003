#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minAddParentheses(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int count = 0, openCount = 0;
    for (char c : s)
    {
        if (c == '(')
            openCount++;
        else if (openCount == 0)
            count++;
        else
            openCount--;
    }
    return count + openCount;
}

int main()
{
    string s;
    cin >> s;

    cout << minAddParentheses(s) << endl;
    return 0;
}
