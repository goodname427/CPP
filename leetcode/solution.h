#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    unordered_map<int, int> cached;
    int max_no;

    inline int get_no(int n, int i, int j)
    {
        return ((n - i - 1) * n) + ((n - i - 1) % 2 ? (n - j) : j + 1);
    }

    inline void get_pos(int n, int no, int &i, int &j)
    {
        i = n - 1 - ((no - 1) / n);
        no =  ((no - 1) % n);
        j = (n - i - 1) % 2 ? n - no - 1 : no; 
    }

    inline int process(const vector<vector<int>> &board, int no)
    {
        if (no == max_no)
            return 0;
        
        if (no > max_no)
            return INT_MAX;

        cout << no << endl;

        if (cached.count(no))
            return cached[no];

        cached[no] = INT_MAX - 1;
        int i, j, res = INT_MAX - 1;
        for (int k = 1; k <= 6; k++)
        {
            if (no + k > max_no)
                break;

            get_pos(board.size(), no + k, i, j);
            res = min(res, min(process(board, board[i][j] != -1 ? board[i][j] : no + k), INT_MAX - 1) + 1);
        }

        return cached[no] = res;
    }

public:
    int snakesAndLadders(const vector<vector<int>>& board) 
    {
        max_no = board.size() * board.size();
        return process(board, 1);
    }
};
