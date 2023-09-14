#include <bits/stdc++.h>
using namespace std;

int mex(set<int> set)//mex函数 获取集合中没有的最小非负整数
{
    if (set.empty())
        return 0;
    for (int i = 0;; i++)
    {
        if (!set.contains(i))
            return i;
    }
}

int main()
{
    set<int> A, B;
    vector<int> all;
    int t, n, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        // 清空集合
        A.clear();
        B.clear();
        all.clear();
        // 输入
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            all.push_back(num);
        }
        // 排序
        sort(all.begin(), all.end());
        
        for (vector<int>::iterator it = all.begin(); it != all.end(); it++)
        {
            // 如果A集合不包含该数字则将该数字插入A集合，否则插入B集合
            if (!A.contains(*it))
                A.insert(*it);
            else
                B.insert(*it);
        }
        //输出结果
        cout << mex(A) + mex(B) << endl;
    }
    return 0;
}
