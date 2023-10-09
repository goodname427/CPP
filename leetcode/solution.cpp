#include <bits/stdc++.h>
using namespace std;

template <class T>
void cout_vector(vector<T> vec)
{
    for (auto e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}
template <class T>
void cout_vector(vector<T> vec, void func(T))
{
    for (auto e : vec)
    {
        func(e);
    }
    cout << endl;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef unsigned long long INT;

    INT numberOfWays(int startPos, int endPos, int k) 
    {
        int diff = endPos - startPos;
        vector<vector<INT>> dp(k + 1, vector<INT>(k + 1, 0));
        startPos = (k - diff) >> 1;
        endPos = startPos + diff;

        dp[0][endPos] = 1;

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                if(j > 0)
                    dp[i][j] += dp[i - 1][j - 1];  
                if(j < dp[0].size() - 1)
                    dp[i][j] += dp[i - 1][j + 1];
            }
        }

        cout_vector(dp, cout_vector);
        return dp[k][startPos];
    }
};

int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{1, 2};
    vector<int> vec2;
    vector<int> vec3;
    cout << solution.numberOfWays(989, 1000, 99) << endl;
    return 0;
}