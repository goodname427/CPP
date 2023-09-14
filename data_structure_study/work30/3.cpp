#include <bits/stdc++.h>
using namespace std;

bool is_(string str, int &index)
{
    index=0;
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
        index++;
    }
    return true;
}
int main()
{
    string str;
    int i, remain, len, result;
    cin >> str;
    while (true)
    {
        result = len = str.length();
        remain = len % 2 == 0 ? 0 : 1;
        if (is_(str, i))
            break;
        if (i*2+remain > len / 2)
        {
            result=i * 2+remain;
            break;
        }
        


    }
    cout << result;
    return 0;
}
