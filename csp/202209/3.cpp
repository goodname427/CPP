#include <bits/stdc++.h>
using namespace std;

class msg
{
public:
    int d;
    int u;
    int r;
};

int main()
{
    int n;
    cin >> n;
    vector<msg> msgs;
    map<int, vector<int>> sites;
    vector<vector<int>> risk_users(n, vector<int>());

    // 输入
    for (int d = 0; d < n; d++)
    {
        int r, m;
        cin >> r >> m;
        // 输入风控地区
        for (int i = 0; i < r; i++)
        {
            int temp;
            cin >> temp;
            sites[temp].push_back(d);
        }
        // 输入漫游消息
        for (int i = 0; i < m; i++)
        {
            msg _m;
            cin >> _m.d >> _m.u >> _m.r;
            msgs.push_back(_m);
        }
    }

    // 风险判断
    for (auto m : msgs)
    {
        if (sites.contains(m.r))
        {
            for (auto risk : sites[m.r])
            {
                if (risk > m.d - 7 && risk <= m.d)
                {
                    for (int i = m.d; i < min(n, m.d + 7); i++)
                        risk_users[i].push_back(m.u);
                    break;
                }
            }
        }
    }

    // 输出
    int i = 0;
    for (auto users : risk_users)
    {
        sort(users.begin(), users.end());
        cout << i << " ";
        for (auto u : users)
        {
            cout << u << " ";
        }
        cout << endl;
        i++;
    }

    return 0;
}
/*
9
1 4 1
0 1 1
-1 1 1
-1 2 1
0 2 2

0 3
0 3 1
1 2 2
1 3 2

0 0

0 0

0 0

0 0

0 0

0 1
5 4 1

1 0 1
*/