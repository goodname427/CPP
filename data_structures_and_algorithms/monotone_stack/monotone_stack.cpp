#include <bits/stdc++.h>
#include "../util/cvectorop"
using namespace std;

// 求数组中 每个元素的 左右两边两个离他最近的小于它的元素
vector<pair<int, int>> solve(vector<int> vec)
{
    vector<pair<int, int>> res(vec.size());
    stack<vector<int>> s;
    for (int i = 0; i < vec.size(); i++)
    {
        // 将单调栈中小于当前元素的元素弹出并结算
        while (!s.empty() && vec[s.top()[0]] < vec[i])
        {
            // 记录栈顶元素然后弹出
            vector<int> eles = s.top();
            s.pop();

            for (auto e : eles)
            {
                // 弹出元素左边的大值为 当前栈顶元素中的 最后一个元素
                res[e].first = s.empty() ? -1 : s.top()[s.top().size() - 1];
                // 弹出元素右边的大值为 当前元素
                res[e].second = i;
            }
        }

        // 如果栈顶元素与当前元素相等,则将两者合并
        if (!s.empty() && vec[s.top()[0]] == vec[i])
            s.top().push_back(i);
        // 否则压入一个全新数组
        else
            s.push(vector<int>{i});
    }


    // 清算剩余元素
    while (!s.empty())
    {
        // 记录栈顶元素然后弹出
        vector<int> eles = s.top();
        s.pop();

        for (auto e : eles)
        {
            // 弹出元素左边的大值为 当前栈顶元素中的 最后一个元素
            res[e].first = s.empty() ? -1 : s.top()[s.top().size() - 1];
            // 弹出元素右边的大值为 空
            res[e].second = -1;
        }
    }

    return res;
}

int main()
{
    vector<int> vec = randomly_vec(10, 20);
    print(vec);
    auto res = solve(vec);
    for (int i = 0; i < res.size(); i++)
        cout << "(" << res[i].first << "," << res[i].second << ") ";
    return 0;
}
