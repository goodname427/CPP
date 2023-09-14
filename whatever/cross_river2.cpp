#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, n, ans, T[1010];
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> T[i];
    sort(T, T + n);
    while (n >= 4)
    {
        a = T[1] * 2 + T[n - 1] + T[0];
        b = 2 * T[0] + T[n - 1] + T[n - 2];
        if (a > b)
            ans += b;
        else
            ans += a;
        n -= 2;
    }
    if (n == 3)
        ans += T[1] + T[0] + T[2];
    else if (n == 2)
        ans += T[1];
    else
        ans += T[0];
    cout << ans << endl;

    return 0;
}