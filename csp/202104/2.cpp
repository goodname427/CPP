#include <bits/stdc++.h>
using namespace std;

#define MAX 605

int n, L, r, t;
int mat[MAX][MAX];

int is_drak(int i, int j)
{
    int total = 0, count = 0;
    for (int x = max(0, i - r); x <= min(n - 1, i + r); x++)
    {
        for (int y = max(0, j - r); y <= min(n - 1, j + r); y++)
        {
            total += mat[x][y];
            count++;
        }
    }
    return total <= t * count;
}

int main()
{
    cin >> n >> L >> r >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            count += is_drak(i, j);
    cout << count;
    return 0;
}
