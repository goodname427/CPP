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
    int findDuplicate(const vector<int>& nums) 
    {
        int n = nums.size();
        int div = 2;
        vector<int> count(div, 0);
        int begin = 1;
        int end = n;
        int len = n / div;
        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] >= begin && nums[i] < end)
                    count[(nums[i] - begin) / len]++;
            }

            cout << begin << " " << end << " " << len << endl;
            cout_vector(count);

            if (len == 2)
                return 1;

            for (int i = 0; i < div; i++)
            {
                if (count[i] > len)
                {
                    if (len == 1)
                        return begin + i;

                    end = begin + (i + 1) * len;
                    begin = begin + i * len;
                    len /= div;
                    break;
                }
            }

            for (int i = 0; i < div; i++)
            {
                count[i] = 0;
            }
        }

        return 0;
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
    cout << solution.findDuplicate({1,5,5,6,2,8,4,7,5,5});
    return 0;
}