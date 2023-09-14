#include <bits/stdc++.h>
using namespace std;

inline double trans(double &x, double &i, int from, int to)
{
    return x * pow(1 + i, to - from);
}

int main()
{
    int n;
    double i;
    cin >> n >> i;
    vector<double> vec(n + 1, 0);

    for (int j = 0; j <= n; j++)
        cin >> vec[j];

    double total = 0;
    for (int j = 0; j <= n; j++)
        total += trans(vec[j], i, j, 0);
    cout << total;
    return 0;
}
