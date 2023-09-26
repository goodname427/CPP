#include <bits/stdc++.h>
#include "stringop.cpp"
using namespace std;

string manacher_str(string &s)
{
    string res = "#";
    for (int i = 0; i < s.length(); i++)
    {
        res += s[i]; 
        res += "#";
    }
    return res;
}

string manacher(string s)
{
    if (s.length() <= 1)
        return s;

    // 在原始字符串的每一个间隔加上一个字符
    string source_str = s;
    s = manacher_str(s);
    // cout << s << endl;

    vector<int> radius(s.length(), 0);
    int c = -1;
    int r = -1;
    int max_r = 0;
    for (int i = 0; i < radius.size(); i++)
    {
        // 获取最小的不用判断的回文半径
        // 1) i在最大回文半径所到达的范围内
        //      1) i'的回文半径全部在最大回文半径内 -> radius[i']
        //      2) i'的回文半径刚好在最大回文半径内 -> radius[i']
        //      3) i'的回文半径一部分在最大回文半径内 -> r - i
        // 2) i不在最大回文半径所到达的范围内 -> 1
        radius[i] = i < r ? min(radius[2 * c - i], r - i) : 1;

        // 从当前回文半径向外扩
        // 如果两边字符相等则扩大回文半径, 否则跳出
        while (i + radius[i] < s.length() && i - radius[i] > -1)
        {
            if (s[i + radius[i]] == s[i - radius[i]])
                radius[i]++;
            else
                break;
        }

        // 比较当前回文半径与最大回文半径, 更新最大回文半径
        if (radius[i] >= max_r)
        {
            c = i;
            r = i + radius[i];
            max_r = radius[i];
        }
    }

    return source_str.substr((c / 2) - ((max_r - 1) / 2) ,max_r - 1);
}
// #1#2#2#1#2#
int main()
{
    string s = randomly_str(20, 3);
    //s = "#a#b#b#a#c#c#a#b#b#a#c#";
    cout << s << endl;
    cout << manacher(s) << endl;
    return 0;
}
