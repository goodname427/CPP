#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, sum = 0;
    cin >> n >> k;
    vector<bool> has_init(n + 1, false);
    has_init[0] = true;
    for (int i = 0; i < k; i++)
    {
        int left, right;
        cin >> left >> right;
        if (left == 0 || !has_init[right])
            sum++;
        has_init[left] = true;
    }
    cout << sum;
    return 0;
}
