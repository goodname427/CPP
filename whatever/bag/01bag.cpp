#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> w(n, 0), v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = c; j >= w[i - 1]; j--)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }

    cout << dp[n][c];
    return 0;
}
/*
5 10
1 2 3 4 5
1 1 1 1 1
*/