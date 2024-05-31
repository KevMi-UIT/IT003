// Not done yet
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

bool isDelimiter(char ch)
{
    return (ch == '.') || (ch == '/');
}

int main()
{
    string path;
    string res = "";
    stack<char> s;
    bool firstCharHasAppeared = false;
    getline(cin, path);
    for (auto &ch : path)
    {
        if (!firstCharHasAppeared && isDelimiter(ch))
        {
            s.push(ch);
            continue;
        }
        else
        {
            firstCharHasAppeared = true;
        }
        if (ch == '/' && s.top() == '.')
        {
            s.pop();
            if (s.top() == '.')
            {
                s.pop();
                s.pop();
                if (!isDelimiter(s.top()))
                    while (s.top() != '/')
                        s.pop();
            }
            continue;
        }
        s.push(ch);
    }
    while (s.top() == '/')
        s.pop();
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
