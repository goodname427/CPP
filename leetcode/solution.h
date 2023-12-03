#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) 
    {
        short x_flag[9];
        short y_flag[9];;
        memset(x_flag, 0, sizeof(short) * 9);
        memset(y_flag, 0, sizeof(short) * 9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                else 
                {
                    int a = 1 << (board[i][j] - '0');
                    if ((x_flag[i] & a) || (y_flag[j] & a))
                        return false;

                    x_flag[i] |= a;
                    y_flag[j] |= a;
                }
            }
        }

        return true;
    }
};