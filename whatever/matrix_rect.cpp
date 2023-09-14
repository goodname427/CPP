#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
                continue;
            sum++;
            if (mat[i][j + 1] != 0)
            {
                int delta = i;
                while (mat[++delta][j] == 0)
                {
                    sum++;
                    if (delta + 1 == n)
                        break;
                }
            }
            if (mat[i + 1][j] != 0)
            {
                int delta = j;
                while (mat[i][++delta] == 0)
                {
                    sum++;
                    if (delta + 1 == n)
                        break;
                }
            }
        }
    }
    cout << "sum:" << sum;
}