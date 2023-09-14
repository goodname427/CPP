#include <bits/stdc++.h>
using namespace std;

bool is_(string str)
{
    int i,len = str.length();
    stack<char> s;
    for (i = 0; i < len / 2; i++)
        s.push(str[i]);
    for (i = (len / 2) + (len % 2 == 0 ? 0 : 1); i < len; i++)
    {
        char top = s.top();
        s.pop();
        if (top != str[i])
            return false;
    }
    return true;
}

int main()
{
    string str;
    cin>>str;
    cout<<(is_(str)?"true":"false");
    return 0;
}
