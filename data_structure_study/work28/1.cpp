#include <bits/stdc++.h>
using namespace std;

int main()
{
#pragma region
// int n, k, num;
// stack<int> s;
// cin >> n;
// k = n;
// for (int i = 0; i < n; i++)
// {
//     cin >> num;
//     s.push(num);
//     if (num == k)
//     {
//         k--;
//         cout << s.top() << " ";
//         s.pop();
//     }
// }
// while (!s.empty())
// {
//     cout << s.top() << " ";
//     s.pop();
// }
#pragma endregion
    int *a = NULL, n, now;
    cin >> n;
    a = new int[n];
    now = n; //当前应当出栈对元素，n一定是第一个出栈的元素
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> s;
    vector<int> vis(n + 1, false); //将已入栈的较大元素标记
    for (int i = 0; i < n; i++)
    {
        s.push(a[i]);
        vis[a[i]] = true;
        while (now > 0 && vis[now])
            now--; //应当出栈的为>=n的元素
        while (!s.empty() && s.top() >= now)
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
