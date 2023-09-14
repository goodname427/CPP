#include <bits/stdc++.h>
using namespace std;

long long f(int n)
{
    long long num[3] = {0, 1, 1};
    for (int i = 2; i < n; i++)
    {
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[0] + num[1];
    }
    return num[2];
}

long long f2(int n, int x = 0, int y = 1)
{
    if (n < 2)
        return y;
    return f2(n - 1, y, x + y);
}

int main()
{
    int n;
    cin >> n;
    cout << f2(n);
    return 0;
}
