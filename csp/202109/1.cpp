#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> B(n, 0);
    for (int i = 0; i < n; i++)
        cin >> B[i];

    int max_sum = B[0], min_sum = B[0];
    for (int i = 1; i < n; i++)
    {
        max_sum += B[i];
        if (B[i] != B[i - 1])
            min_sum += B[i];
    }
    cout << max_sum << endl
         << min_sum << endl;
    return 0;
}
