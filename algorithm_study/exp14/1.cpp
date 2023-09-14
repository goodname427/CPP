#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

bool dp[MAX][MAX];

int get_sum(vector<int> vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
        sum += vec[i];
    return sum;
}

bool dp_solve(vector<int> vec)
{
    int sum = get_sum(vec), n = vec.size();
    //如果和为奇数则返回false
    if (sum % 2 != 0)
        return false;
    sum /= 2;
    //初始化
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    //动态规划求解
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= vec[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - vec[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        cout<<(dp_solve(vec)?"true":"false")<<endl;
    }

    return 0;
}
