#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, w;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> s;
        total += w * s;
    }
    cout << max(0, total);
    return 0;
}
