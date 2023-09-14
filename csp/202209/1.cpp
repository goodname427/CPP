#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    //输入
    cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //获取c数组
    auto c = a;
    for (int i = 1; i < n; i++)
    {
        c[i] *= c[i - 1];
    }
    //获取b数组并输出
    for (int i = 0; i < n; i++)
    {
        int k = (i == 0 ? 1 : c[i - 1]);
        int b = m % c[i] / k;
        m -= b * k;
        cout << b << " ";
    }

    return 0;
}
