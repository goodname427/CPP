#include <bits/stdc++.h>
using namespace std;

bool is_number(char ch)
{
    return ch <= '9' && ch >= '0';
}
//从表达式中获取操作符并且返回操作数
char get_operator(string expre, int &left, int &right)
{
    int index = 0;
    while (is_number(expre[index]) || expre[index] == ' ')
        index++;
    left = atoi(expre.substr(0, index).c_str()); //获取左操作数
    auto oper = expre[index];
    while (!is_number(expre[index]))
        index++;
    right = atoi(expre.substr(index, expre.length() - index).c_str()); //获取右操作数
    return oper;
}

//计算简单表达式
int operate(string expre)
{
    int l, r;
    char oper = get_operator(expre, l, r);
    switch (oper)
    {
    case '+':
        return l + r;
        break;
    case '-':
        return l - r;
        break;
    case '*':
        return l * r;
        break;
    case '/':
        return l / r;
        break;
    case '%':
        return l % r;
        break;
    default:
        break;
    }
    return 0;
}

int main()
{
    string expre;
    getline(cin, expre);
    cout << operate(expre) << endl;
    return 0;
}