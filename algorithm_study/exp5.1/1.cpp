#include <bits/stdc++.h>
using namespace std;

int solve(int *start, int *end, int sign)
{
    if (start == end)
        return 0;
    return max(solve(start + 1, end, sign), *start * sign + solve(start + 1, end, -sign));
}

int main()
{
    int n, *a = NULL;
    //输入
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //求解
    cout << solve(a, a + n, 1) << endl;
    return 0;
}
/*
7
1 2 5 4 3 6 7
9

2^(n+1)
*/
