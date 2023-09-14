#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    vector<int> left(n + 1, 0), right(n + 1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        left[i] = A[i] - A[i - 1];
        right[i] = A[i] - A[i + 1];
    }

    return 0;
}
