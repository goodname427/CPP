#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int total[MAX];

// t in [q+k,q+k+c)
// q+k <= t < q+k+c
// q <= t-k q > t-k-c
// (t-k-c,t-k]
int main()
{
    int n, m, k, q;
    cin >> n >> m >> k;
    memset(total, 0, sizeof(int) * MAX);
    while (n--)
    {
        int t, c;
        cin >> t >> c;
        int begin = max(0, t - k - c + 1), end = min(t - k + 1, MAX);
        for (int j = begin; j < end; j++)
            total[j]++;
    }
    while (m--)
    {
        cin >> q;
        cout << total[q] << endl;
    }
    return 0;
}
/*
6 2 10
5 24
10 24
11 24
34 24
35 24
35 48
1
2
*/