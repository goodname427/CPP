#include <bits/stdc++.h>
using namespace std;

typedef long ll;

ll r;

inline ll g(ll x)
{
    return floor(x * 1.0 / r);
}

int main()
{
    int n, N, j = 0, total = 0,A;
    cin >> n >> N;
    r = floor(N * 1.0 / (n + 1));
    for (ll i = 1; i <= n; i++)
    {
        cin >> A;
        for (; j < A; j++)
            total += abs(i - 1 - g(j));
    }
    for (; j < N; j++)
        total += abs(n - g(j));

    cout << total;
    return 0;
}
