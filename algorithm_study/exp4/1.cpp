#include <bits/stdc++.h>
using namespace std;

string ops[100];

//输入操作数和操作符进行运算
int operate(int op1, int op2, char op)
{
    switch (op)
    {
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    default:
        return 0;
    }
}

void exp()
{
    string s;
    stack<int> op;
    while (cin >> s)
    {
        if (s == "#") // 输出结束
            break;

        if (regex_match(s, regex("[0-9]+"))) // 判断是否输入数字，如果输入数字则将操作数入栈
        {
            op.push(atoi(s.c_str()));
        }
        else // 否则取出栈顶两元素进行运算，然后将结果入栈
        {
            int op2 = op.top();
            op.pop();
            int op1 = op.top();
            op.pop();
            op.push(operate(op1, op2, s[0]));
        }
    }
    cout << op.top();
}

int exp(int &i)
{
    int x, y;
    switch (ops[i][0])
    {
    case '+':
        return exp(--i) + exp(--i);
    case '-':
        y = exp(--i);
        x = exp(--i);
        return x - y;
    case '*':
        return exp(--i) * exp(--i);
    case '/':
        y = exp(--i);
        x = exp(--i);
        return x / y;
    default:
        return atoi(ops[i].c_str());
    }
}

void input()
{
    int n = 0;
    while (cin >> ops[n++])
    {
        if (cin.get() == '\n')
            break;
    }
    cout << exp(--n);
}

int main()
{
    input();
    return 0;
}
// 3 5 2 - * 7 + #
// 3 5 2 - * 7 +
// 16