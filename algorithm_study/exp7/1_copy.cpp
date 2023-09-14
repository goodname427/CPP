#include <bits/stdc++.h>
using namespace std;

int minSteps(int height[], int begin, int end, int h)
{
    if (begin >= end)
        return 0;

    int _min = begin;
    for (int i = begin; i < end; i++)
        if (height[i] < height[_min])
            _min = i;

    return min(end - begin,
               minSteps(height, begin, _min, height[_min]) +
                   minSteps(height, _min + 1, end, height[_min]) +
                   height[_min] - h);
}

int main()
{
    //输入
    int N;
    cin >> N;
    int *height = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
    }
    cout << minSteps(height, 0, N, 0) << endl;
    return 0;
}
