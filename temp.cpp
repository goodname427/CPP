#include <bits/stdc++.h>
using namespace std;

int numberOfWays(int startPos, int endPos, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(2 * k + 1, 0));
    startPos += k;
    endPos += k;

    dp[0][endPos] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < dp.size(); j++)
        {
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1];
            if (j < dp.size() - 1)
                dp[i][j] += dp[i - 1][j + 1];
        }
    }

    return dp[k][startPos];
}

int main()
{
}
