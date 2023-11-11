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
    int search(vector<int> &nums, int &target, bool lowwer, int l, int r)
    {
        if (l > r)
            return -1;

        int mid = l + ((r - l) >> 1);

        if (nums[mid] == target)
        {
            int res = lowwer? 
                search(nums, target, lowwer, l, mid - 1): 
                search(nums, target, lowwer, mid + 1, r);
            
            return res != -1 ? res : mid;
        }

        if (target < nums[mid])
            return search(nums, target, lowwer, l, mid - 1);

        return search(nums, target, lowwer, mid + 1, r); 
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {   
        return {
            search(nums, target, 0, true, nums.size() - 1),
            search(nums, target, 0, false, nums.size() - 1)
        };
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
    cout_vector(solution.searchRange(vec1, 8));
    return 0;
}