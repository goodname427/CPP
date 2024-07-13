#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    template<class Accessor>
    int bs(Accessor accessor, int target, int l, int r)
    {
        if (l > r)
        {
            return -1;
        }

        int mid = l + ((r - l) >> 1);
        int left;
        
        if (target == accessor(mid))
        {
            return mid;
        }

        if (target < accessor(mid))
        {
            return bs(accessor, target, l, mid - 1);
        }
        else
        {
            int right = bs(accessor, target, mid + 1, r);
            return right == -1 ? mid : right;
        }
    }

    bool searchMatrix(const vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0)
        {
            return false;
        }

        int row = bs([&matrix](int i){ return matrix[i][0]; }, target, 0, matrix.size());

        if (row == -1)
        {
            return false;
        }

        if (matrix[row][0] == target)
        {
            return true;
        }

        int col = bs([&matrix, row](int i){ return matrix[row][i]; }, target, 0, matrix[row].size());

        return (col != -1 && matrix[row][col] == target);
    }
};
