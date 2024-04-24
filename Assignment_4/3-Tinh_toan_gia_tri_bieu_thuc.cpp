#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(const string &infixExpr)
{
    stack<char> operators;
    string postfixExpr = "";

    for (char c : infixExpr)
    {
        if (isdigit(c))
        {
            postfixExpr += c; // Append operand directly to output
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c))
            {
                postfixExpr += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfixExpr += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '(' from stack
        }
    }

    while (!operators.empty())
    {
        postfixExpr += operators.top();
        operators.pop();
    }

    return postfixExpr;
}

int evaluatePostfix(const string &postfixExpr)
{
    stack<int> operands;

    for (char c : postfixExpr)
    {
        if (isdigit(c))
        {
            operands.push(c - '0'); // Push operand (convert char to int)
        }
        else if (isOperator(c))
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
    }

    return operands.top(); // Result is the top of the stack
}

int main()
{
    string infixExpr;
    getline(cin, infixExpr);
    string postfixExpr = infixToPostfix(infixExpr);
    int result = evaluatePostfix(postfixExpr);
    cout << result << endl;

    return 0;
}
