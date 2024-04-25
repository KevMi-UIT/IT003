#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

vector<char> infixToPostfix(const string &infixExpr)
{
    stack<char> operators;
    vector<char> postfixExpr;

    for (char c : infixExpr)
    {
        if (isdigit(c))
            postfixExpr.push_back(c);
        else if (c == '(')
            operators.push(c);
        else if (c == ')')
            while (operators.top() != '(')
            {
                postfixExpr.push_back(operators.top());
                operators.pop();
            }
        else if (!operators.empty() and precedence(operators.top()) >= precedence(c))
        {
            postfixExpr.push_back(operators.top());
            operators.pop();
            operators.push(c);
        }
        else
            operators.push(c);
    }

    while (!operators.empty())
    {
        // postfixExpr += operators.top();
        postfixExpr.push_back(operators.top());
        operators.pop();
    }

    return postfixExpr;
}

long evaluatePostfix(const vector<char> &postfixExpr)
{
    stack<long> operands;

    for (char c : postfixExpr)
        if (isdigit(c))
            operands.push(c - '0');
        else
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            switch (c)
            {
            case '+':
                operands.push(a + b);
                break;
            case '-':
                operands.push(a - b);
                break;
            case '*':
                operands.push(a * b);
                break;
            case '/':
                operands.push(a / b);
                break;
            }
        }

    return operands.top();
}

int main()
{
    string infixExpr;
    getline(cin, infixExpr);
    vector<char> postfixExpr = infixToPostfix(infixExpr);
    long result = evaluatePostfix(postfixExpr);
    cout << result << endl;

    return 0;
}
