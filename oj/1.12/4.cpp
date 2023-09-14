#include <bits/stdc++.h>
using namespace std;

#define MAX 105
int mat[MAX][MAX];
int _mat[MAX][MAX];
int m, n, r, s;

void input_mat(int mat[MAX][MAX], int h, int w)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> mat[i][j];
}

int match(int row, int col)
{
    int sum = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < s; j++)
        {
            sum += abs(mat[row + i][col + j] - _mat[i][j]);
        }
    return sum;
}

int main()
{
    cin >> m >> n;
    input_mat(mat, m, n);
    cin >> r >> s;
    input_mat(_mat, r, s);
    int min = -1, min_row = -1, min_col = -1;
    for (int i = 0; i <= m - r; i++)
        for (int j = 0; j <= n - s; j++)
        {
            int sum = match(i, j);
            if (min == -1 || min > sum)
            {
                min = sum;
                min_row = i;
                min_col = j;
            }
        }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
            cout << mat[min_row + i][min_col + j] << " ";
        cout << endl;
    }
    return 0;
}