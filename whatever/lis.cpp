#include <iostream>
using namespace std;

int lis(int arr[], int len)
{
    //初始化
    int longest[len];
    for (int i = 0; i < len; i++)
    {
        longest[i] = 1;
    }

    for (int j = 1; j < len; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[j] > arr[i] && longest[j] < longest[i] + 1) // 注意longest[j] 小于 longest[i]+1 不能省略,用于寻找最大值
            {
                longest[j] = longest[i] + 1; // 计算以arr[j]结尾的序列的最长递增子序列的长度
            }
        }
    }

    int max = 0;
    for (int j = 0; j < len; j++)
    {
        cout << "longest[" << j << "]=" << longest[j] << endl;
        if (longest[j] > max)
            max = longest[j]; // 从longest[j]中找出最大值，即为最长长度
    }
    return max;
}
int main()
{
    int arr[] = {2, 3, 4, 1, 8, 5, 6}; // 测试数组
    cout << "LIS:"<<endl
         << lis(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}