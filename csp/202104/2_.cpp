#include <bits/stdc++.h>
using namespace std;

#define MAX 605

int n, L, r, t;
int mat[MAX][MAX];

int main()
{
    cin >> n >> L >> r >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<vector<int>> front(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            front[i][j] = front[i - 1][j] + front[i][j - 1] - front[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int min_i = max(i - r, 0), min_j = max(j - r, 0), max_i = min(i + r + 1, n), max_j = min(j + r + 1, n);
            int total = front[max_i][max_j] - front[max_i][min_j] - front[min_i][max_j] + front[min_i][min_j];
            if (total <= (t * ((max_i - min_i) * (max_j - min_j))))
                count++;
        }
    }
    cout << count;

    return 0;
}
