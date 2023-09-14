#include <iostream>
#include <stack>
using namespace std;

bool Judge(string str)
{
    stack<char> s;
    //{{()}()}[[{}]]{}
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
            s.push(str[i]);
        else
        {
            if (str[i] == '{' || str[i] == '[' || str[i] == '(')
                s.push(str[i]);
            else
            {
                auto top = s.top();
                if ((top == '{' && str[i] == '}') || (top == '(' && str[i] == ')') || (top == '[' && str[i] == ']'))
                    s.pop();
                else
                    return false;
            }
        }
    }   
    return s.empty();
}

int main()
{
    string str;
    while (cin >> str)
        cout << Judge(str);
    return 0;
}