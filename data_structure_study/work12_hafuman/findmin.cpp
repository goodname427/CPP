#include <iostream>
using namespace std;

int main()
{
    int nums[] = {12, 33, 3, 5,14, 43, 55, 75,1};
    int i = 0;
    int min1 = nums[i++], min2 = nums[i++];
    for (; i < sizeof(nums) / sizeof(int); i++)
    {
        if (nums[i] < min1)
        {
            if (min1 < min2)
                min2 = min1;
            min1 = nums[i];
            continue;
        }
        if (nums[i] < min2)
            min2 = nums[i];
    }
    cout << min1 << " " << min2;
    return 0;
}