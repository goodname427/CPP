#include <bits/stdc++.h>
using namespace std;

bool is_(string str, int &i, int &remain)
{
    stack<char> s;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        if (str[i] == ')')
        {
            if (s.empty())
                return false;
            char top = s.top();
            s.pop();
            if (top == ')')
                return false;
        }
    }
    remain = s.size();
    return s.empty();
}

int main()
{
    string str;
    int i, remain, flg = false;
    cin >> str;
    while (!flg)
    {
        flg = is_(str, i, remain);
        if (flg)
            break;
        if (i == str.length())
        {
            str = str.substr(remain, str.length() - remain);
            break;
        }
        if (i > str.length() / 2)
        {
            str = str.substr(0, i);
            break;
        }
        str = str.substr(i + 1, str.length() - i - 1);
    }
    cout << str.length();
    return 0;
}

/*
((())
()())
)()()
*/