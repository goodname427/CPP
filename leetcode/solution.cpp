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
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{5, 7, 7, 8, 8, 10};
    vector<int> vec2;
    vector<int> vec3;
    vector<vector<int>> vec4 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    //                      1 2 3 4 2 1

    //cout << solution.calcEquation({{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}});
    //cout << solution.calcEquation({{"a","b"},{"b","c"}}, {2.0,3.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}});
    // cout << vector<vector<string>> {{"a","b"},{"b","c"}};
    cout << vector<string> {"b","c"};
    return 0;
}