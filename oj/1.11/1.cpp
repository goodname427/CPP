#include <bits/stdc++.h>
using namespace std;

int *nums;
int len1;

bool is_in_range(int index)
{
    return index >= 0 && index < len1;
}

int get(int target, int mid)
{
    int min = INT32_MAX, index;
    for (int i = -1; i <= 1; i++)
    {
        if (is_in_range(mid + i))
        {
            int dis = abs(nums[mid + i] - target);
            if (min < dis)
            {
                min = dis;
                index = mid + i;
            }
        }
    }
    return index;
}

int find(int target)
{
    int min = 0, max = len1, mid;
    while (1)
    {
        if (min >= max)
        {
            if (min >= len1)
                return nums[len1 - 1];
            if (min < 0)
                return nums[0];
            return nums[get(target, min)];
        }
        mid = (max + min) / 2;
        if (nums[mid] == target)
            return target;
        if (nums[mid] < target)
            min = mid + 1;
        else
            max = mid - 1;
    }
}

int main()
{
    int len2, *ques = NULL;
    cin >> len1;
    nums = new int[len1];
    for (int i = 0; i < len1; i++)
    {
        cin >> nums[i];
    }
    cin >> len2;
    ques = new int[len2];
    for (int i = 0; i < len2; i++)
    {
        cin >> ques[i];
    }
    for (int i = 0; i < len2; i++)
    {
        cout << find(ques[i]) << endl;
    }
    return 0;
}
