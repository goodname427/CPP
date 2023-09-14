#include <bits/stdc++.h>
using namespace std;

#define _INFINITY INT_MAX

int _min = _INFINITY;

int cross_river(vector<int> arr, vector<int>::iterator ele1, vector<int>::iterator ele2, int cost = 0)
{
    //移出已经过河的人
    if (ele1 != arr.end())
        arr.erase(ele1);
    if (ele2 != arr.end())
        arr.erase(ele2);

    vector<int> result_list; //结果集
    int result;              //最终结果

    if (arr.size() == 0)
    {
        result = 0;
    }
    else if (arr.size() == 1) //如果当前只有一个人，那么过河时间就是这个人的时间
    {
        result = arr[0];
    }
    else
    {
        //选择两个人过河
        for (auto i = arr.begin(); i != arr.end(); i++)
        {
            for (auto j = arr.begin(); j != i; j++)
            {
                auto _cost = max(*i, *j); //这两个人过河的耗时
                if (cost + _cost > _min)  //耗时大于已有的最小值则跳过该组合
                    continue;
                //记录结果集
                result_list.push_back(_cost + cross_river(arr, i, j, cost + _cost));
            }
        }
        //获取最短耗时
        result = result_list[0];
        for (auto i = 1; i < result_list.size(); i++)
        {
            if (i < result)
                result = i;
        }
    }

    if (arr.size() <= 1 && result < _min)
    {
        _min = result;
    }

    return result;
}

int main()
{
    int n, temp;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    cout << cross_river(arr, arr.end(), arr.end());
    return 0;
}
