#include <iostream>
#include <stack>
using namespace std;

bool isValidExpression(string s)
{
    stack<char> brackets;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            brackets.push(c);
        else if (c == ')' || c == ']' || c == '}')
        {
            if (brackets.empty())
                return false;
            char openBracket = brackets.top();
            brackets.pop();
            if ((c == ')' && openBracket != '(') || (c == ']' && openBracket != '[') ||
                (c == '}' && openBracket != '{'))
                return false;
        }
    }
    return brackets.empty();
}

int main()
{
    string S;
    getline(cin, S);
    cout << isValidExpression(S);
}