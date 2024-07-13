#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for (auto e : vec)
    {
        os << e << " ";
    }

    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec)
{
    for (auto e : vec)
    {
        os << e << endl;
    }

    return os;
}

int main()
{
    Solution solution;

    // int i, j;
    // solution.get_pos(6, 35, i, j);
    // cout << i << " " << j;
    cout << solution.searchMatrix(
        { { 1, 4, 7, 11, 15 },
          { 2, 5, 8, 12, 19 },
          { 3, 6, 9, 16, 22 },
          { 10, 13, 14, 17, 24 },
          { 18, 21, 23, 26, 30 } }, 5);
    return 0;
}