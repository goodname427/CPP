#include <bits/stdc++.h>
using namespace std;

int sort(int *array, int n)
{
    int count = 0, temp;
    // 简单冒泡排序
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (array[j - 1] > array[j])
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                count++; // 计数器记录交换次数
            }
        }
    }
    return count;
}

int main()
{
    string str;
    int t, n, *array = NULL;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (array != NULL)
            delete[] array;
        array = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> array[j]; // 输入
        }
        // 判断并输出结果
        cout << (sort(array, n) > ((n * (n - 1) / 2) - 1) ? "NO" : "YES") << endl;
    }
    if (array != NULL)
        delete[] array;
    return 0;
}
