#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int dp[MAX][3];

void solve(int w, int m, int n)
{
    //初始化
    memset(dp[0], 0, sizeof(int) * 3);
    for (int i = 1; i <= w; i++)
    {
        // i<m时无法安装货架，dp[i]=dp[i-1]+1
        if (i < m)
        {
            memcpy(dp[i], dp[i - 1], sizeof(int) * 3);
            dp[i][0]++;
        }
        // i<=n时选择dp[i-n]和dp[i-m]中剩余长度小的，dp[i]=min(dp[i-m],dp[i-n])
        else if (i >= n)
        {
            if (dp[i - m][0] < dp[i - n][0])
            {
                memcpy(dp[i], dp[i - m], sizeof(int) * 3);
                dp[i][1]++;
            }
            else
            {
                memcpy(dp[i], dp[i - n], sizeof(int) * 3);
                dp[i][2]++;
            }
        }
        // i<n,i>=m时dp[i]=dp[i-m]
        else if (i >= m)
        {
            memcpy(dp[i], dp[i - m], sizeof(int) * 3);
            dp[i][1]++;
        }
    }
}

int main()
{
    int t, w, n, m, m_count, n_count;
    cin >> t;
    while (t--)
    {
        cin >> w >> m >> n;
        solve(w, m, n);
        cout << dp[w][1] << " " << dp[w][2] << " " << dp[w][0] << endl;
    }
    return 0;
}
