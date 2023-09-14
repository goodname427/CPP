#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class date
{
public:
    int month;
    int day;
    friend bool operator<(const date &l, const date &r)
    {
        if (l.month < r.month)
            return true;
        if (l.month == r.month && l.day < r.day)
            return true;
        return false;
    }
    friend bool operator==(const date &l, const date &r)
    {
        return r.month == l.month && l.day == r.day;
    }
};

bool comp(string &l, string &r)
{
    if (l.length() < r.length())
        return true;
    else if (l.length() == r.length())
        return l.compare(r) < 0;
    return false;
}

int main()
{
    int n;
    cin >> n;
    multimap<date, string> students;
    for (int i = 0; i < n; i++)
    {
        string name;
        date d;
        cin >> name;
        cin >> d.month;
        cin >> d.day;
        students.insert(pair<date, string>(d, name));
    }
    const date *key = NULL;
    vector<string> names;
    bool isNone = true; //记录是否为空
    for (auto pair = students.begin(); pair != students.end(); pair++)
    {
        if (key != NULL && pair->first == *key) //相同键跳过
            continue;
        key = &(pair->first);//记录当前键
        auto vals = students.equal_range(pair->first); //获取所有具有相同键的名字
        auto s = vals.first;
        if (++s == vals.second) //没有多个值则跳过
            continue;
        isNone = false;
        //添加所有具有相同键的值
        names.clear();
        for (auto it = vals.first; it != vals.second; it++)
            names.push_back(it->second);
        //排序
        sort(names.begin(), names.end(), comp);
        //输出
        cout << key->month << " " << key->day << " ";
        for (auto it = names.begin(); it != names.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    if (isNone)//如果为空输出None
        cout << "None";
    return 0;
}