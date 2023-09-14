#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, N;
    cin >> n >> N;
    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    int sum = 0;
    vector<int> f(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = f[i]; j <= n + 1; j++)
        {
            if (j == n + 1 || vec[j] > i)
            {
                f[i + 1] = j - 1;
                sum += j - 1;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}
