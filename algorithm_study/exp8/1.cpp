#include <bits/stdc++.h>
using namespace std;

//获取数组begin至end元素的和
int get_sum(int *arr, int begin, int end)
{
    int sum = 0;
    for (int i = begin; i < end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int get_min_page(int *arr, int begin, int end, int m)
{
    //只剩一个人时最小分配页数就是数组当前剩下元素的和
    if (m == 1)
        return get_sum(arr, begin, end);

    int _min = -1;
    for (int i = begin + 1; i <= end - m + 1; i++)
    {
        //分配后最大页数
        int temp = max(get_sum(arr, begin, i),
                       get_min_page(arr, i, end, m - 1));
        //所有可能的最小分配页数
        if (temp < _min || _min == -1)
            _min = temp;
    }
    return _min;
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << get_min_page(arr, 0, n, m) << endl;
        delete[] arr;
    }

    return 0;
}
/*
2
4 2
12 34 67 90
15 7
12 34 67 90 95 103 150 165 170 198 201 235 240 245 251
*/