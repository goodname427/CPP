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
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C, int i)
    {
        if (i == 1)
        {
            B.push_back(A[A.size() - 1]);
            A.pop_back();
            return;
        }
        
        hanota(A, C, B, i - 1);
        hanota(A, B, C, 1);
        hanota(C, B, A, i - 1);
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
    {
        if (A.size() == 0)
            return;

        hanota(A, B, C, A.size());
    }
};
int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1 {1, 2};
    vector<int> vec2;
    vector<int> vec3;
    solution.hanota(vec1, vec2, vec3);
    cout_vector(vec1);
    cout_vector(vec2);
    cout_vector(vec3);
    // auto r = solution.candy({2, 1, 2});
    // cout << 1;
    return 0;
}