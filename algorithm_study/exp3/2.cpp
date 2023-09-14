#include <bits/stdc++.h>
using namespace std;

//全局变量，记录ip是否可分解
bool has;

//判断数字是否合法
bool in_range(string num)
{
    if (num[0] == '0' && num.length() > 1)
        return false;
    int i = atoi(num.c_str());
    return i <= 255 && i >= 0;
}

//打印ip
void print(vector<string> ip)
{
    for (int i = 0; i < ip.size(); i++)
    {
        cout << ip[i] << (i < ip.size() - 1 ? "." : "");
    }
    cout << endl;
}

//分解ip
void split_ip(string str, vector<string> ip, int begin, int length)
{
    if (length != 0) // 统一接口
    {
        string sub = str.substr(begin, length);
        if (!in_range(sub)) // 判断当前数字是否合法，不合法跳出迭代
            return;
        ip.push_back(sub);
        begin += length;
    }
    if (begin < str.length() && ip.size() < 4) // 判断是否可以继续添加数字
        for (int i = 1; i <= 3; i++)
        {
            if (begin + i > str.length())
                return;
            split_ip(str, ip, begin, i);
        }
    else if (ip.size() == 4 && begin >= str.length()) // 判断当前ip是否合法，合法则输出结果
    {
        has = true;
        print(ip);
    }
}

//获取所有合法ip
void get_valid_ip(string str)
{
    has = false;
    vector<string> ip;
    split_ip(str, ip, 0, 0);
    if (!has)
        cout << -1 << endl;
}

int main()
{
    int t;
    string str;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> str;
        if (str.length() < 4 || str.length() > 12)
            cout << -1 << endl;
        else
            get_valid_ip(str);
    }
    return 0;
}
/*
1
25525511135
*/