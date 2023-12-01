#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(vector<T> vec)
{
    for (auto e : vec)
    {
        cout << e << " ";
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

class Solution {
public:
    int candy(const vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int> left(n, 0);
        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                left[i] = left[i - 1] + 1;
            }
            else if (ratings[i - 1] == ratings[i])
            {
                left[i] = 1;
            }
            else
            {
                left[i] = 1;
            }
        }

        vector<int> right(n, 0);
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
            else if (ratings[i] == ratings[i + 1])
            {
                right[i] = 1;
            }
            else
            {
                right[i] = 1;
            }
        }

        print(left);
        print(right);

        int res = 0;
        for (int i = 0; i < n; i++)
            res += max(left[i], right[i]);

        return res;
    }
};

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
    cout << solution.candy({0,1,2,3,2,1});
    return 0;
}