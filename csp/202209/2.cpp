#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum;
    cin >> n >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    x = sum - x;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j > a[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << sum - dp[n][x];
    return 0;
}
/*
4 100
20
90
60
60
*/