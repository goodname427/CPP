#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

template <class T>
void print(vector<T> vec)
{
    for (auto e : vec)
    {
        cout << e << ' ';
    }
    cout << endl;
}
template <class T>
void print(vector<T> vec, void func(T))
{
    for (auto e : vec)
    {
        func(e);
    }
    cout << endl;
}

int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{5,7,7,8,8,10};
    vector<int> vec2;
    vector<int> vec3;
    vector<vector<int>> vec4 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    //                      1 2 3 4 2 1
    cout << solution.isValidSudoku({
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    });
    return 0;
}