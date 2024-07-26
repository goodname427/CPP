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
    cout << solution.printKMoves(4);
    return 0;
}