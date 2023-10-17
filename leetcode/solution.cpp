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

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i)
        {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i])
            {
                j = fail[j];
            }
            if (s[j + 1] == s[i])
            {
                fail[i] = j + 1;
            }
        }
        return s.substr(0, fail[n - 1] + 1);
    }
};

int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{1, 2};
    vector<int> vec2;
    vector<int> vec3;
    cout << solution.longestPrefix("bba") << endl;
    return 0;
}