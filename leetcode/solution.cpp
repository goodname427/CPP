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

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) 
    {
        queue<pair<int, int>> q;
        int remind = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    remind++;
                }
            }
        }

        int res = 2;
        int dir[] = {1, 0, -1, 0, 0, 1, 0, -1};
        while (!q.empty())
        {
            pair<int, int> pos = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = pos.first + dir[2 * i];
                int y = pos.second + dir[2 * i + 1];
            
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                    continue;

                grid[x][y] = grid[pos.first][pos.second] + 1;
                q.push({x, y});
                res = grid[x][y];
                
                // if(--remind == 0)
                //     return res;
            }
        }

        return remind ? -1 : (res - 2);
    }
};

int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{1, 2};
    vector<int> vec2;
    vector<int> vec3;
    vector<vector<int>> vec4 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << solution.orangesRotting(vec4) << endl;
    return 0;
}